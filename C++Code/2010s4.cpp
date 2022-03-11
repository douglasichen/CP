#include <bits/stdc++.h>
using namespace std;

// input
int N;

// graphs
vector<vector<int>> g;	// node1 -> { node2, ... }
vector<vector<int>> spanG;

// map data
unordered_map<int, unordered_map<int,vector<int>>> hasEdge;
unordered_map<int,unordered_map<int,int>> edgeCosts;
unordered_map<int,unordered_map<int,int>> gCosts;
unordered_map<int,unordered_map<int,bool>> setCost;

// data
vector<vector<int>> edgePens; //cost

vector<int> minSpan(bool out) {
	int start=0;

	// within the pens:
	vector<bool> vis(N+1);
	vis[start]=1;
	vector<int> sels={start};

	int totalCost=0;
	while ((int)sels.size()<N) {
		// get best pen to go to
		// int from=-1;
		vector<int> best={-1,INT_MAX};
		for (int a : sels) {
			for (int b : g[a]) {
				if (!vis[b]) {
					int cost=gCosts[a][b], bestCost=best[1];
					if (cost<bestCost) {
						best={b,cost};
						// from=a;
					}
				}
			}
		}

		int newPen=best[0], cost=best[1];
		if (newPen==-1) break;	// if invalid break, (group of pens detached)
		
		vis[newPen]=1;
		sels.push_back(newPen);

		// cout << "from " << from << " to " << newPen << " costs " << cost << endl;
		
		// increment cost
		totalCost+=cost;
	}

	// cout << "visited: " << sels.size() << endl;

	return {totalCost,(int)sels.size()};
	

}

int getOutsideCost() {
	// might be empty space in middle, other than that...
	// add all edge pens to outside node;
	int outNode=N;
	for (vector<int> penData : edgePens) {
		int pen=penData[0], cost=penData[1];
		g[pen].push_back(outNode);
		g[outNode].push_back(pen);

		// update cost matrix
		gCosts[pen][outNode]=cost;
		gCosts[outNode][pen]=cost;
	}

	return minSpan(true)[0];
}


void solve() {
	vector<int> data=minSpan(false);
	int totalCost=data[0];
	int spanCount=data[1];

	// what if they went outside?
	int outsideCost=getOutsideCost();
	int ans=min(outsideCost,totalCost);
	
	if (spanCount<N)
		ans=outsideCost;
	
	cout << ans << endl;
}


int main() {
	cin>>N;
	g=*(new vector<vector<int>>(N+1));
	spanG=g;
	// edgeCosts=*(new vector<vector<int>>(N,*(new vector<int>(N,INT_MAX))));

	vector<vector<int>> connectedEdges, nonConEdges;
	for (int i=0; i<N; i++) {
		// input
		int E; cin>>E;
		vector<int> points(E), costs(E);
		for (int p=0; p<E; p++)
			cin>>points[p];
		for (int c=0; c<E; c++)
			cin>>costs[c];

		// edges
		vector<vector<int>> edges;
		for (int p=0; p<E; p++) {
			vector<int> edge(2);
			if (p<E-1) 
				edge={points[p],points[p+1]};
			else 
				edge={points.back(), points.front()};

			// add to has edge list so others can attach to it 
			hasEdge[edge[0]][edge[1]].push_back(i);
			hasEdge[edge[1]][edge[0]].push_back(i);

			// add to edges list
			edges.push_back(edge);

			// add to connected edges list if there is >=2 connections for the points
			if (hasEdge[edge[0]][edge[1]].size()==2) {
				connectedEdges.push_back(edge);
			}
			
			// map minimum cost for connection
			int prevCost=edgeCosts[edge[0]][edge[1]], cost=costs[p];
			if (!setCost[edge[0]][edge[1]]) {
				edgeCosts[edge[0]][edge[1]]=cost;
				edgeCosts[edge[1]][edge[0]]=cost;

				// boolean
				setCost[edge[0]][edge[1]]=1;
				setCost[edge[1]][edge[0]]=1;
			}
			else {
				edgeCosts[edge[0]][edge[1]]=min(prevCost, cost);
				edgeCosts[edge[1]][edge[0]]=min(prevCost, cost);
			}
		}

		// generate nonConEdges
		vector<int> minNonConEdge={-1,INT_MAX};
		for (vector<int> edge : edges) {
			if (hasEdge[edge[0]][edge[1]].size()==1) {
				// found one connected to outside
				int pen=i;
				// edgePens.push_back(pen);
				// break;

				int cost=edgeCosts[edge[0]][edge[1]], prevCost=minNonConEdge[1];
				if (cost<prevCost) {
					minNonConEdge={pen,cost};
				}
			}
		}
		
		// if found an edge connected to outside
		int pen=minNonConEdge[0], cost=minNonConEdge[1];
		if (pen!=-1) {
			edgePens.push_back({pen,cost});
		}
	}



	// add each connection to graph
	for (vector<int> edge : connectedEdges) {
		vector<int> pensConnected=hasEdge[edge[0]][edge[1]];
		
		// assuming 2 pens connected, add the connection to the graph
		int a=pensConnected[0], b=pensConnected[1];
		g[a].push_back(b);
		g[b].push_back(a); 

		// gCost map
		gCosts[a][b]=edgeCosts[edge[0]][edge[1]];
		gCosts[b][a]=edgeCosts[edge[0]][edge[1]];
	}
	
	solve();

}