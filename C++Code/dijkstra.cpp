#include <bits/stdc++.h>
using namespace std;

int n,m;
unordered_map<int,vector<vector<int>>> g;

int dijkstra(int a, int b) {
	vector<int> shortest(n+1,INT_MAX);
	shortest[a]=0;
	unordered_map<int,bool> isSel;

	int check=a;

	while (check!=-1) {
		// if infinite, it is not attached to start node in any way.
		if (shortest[check]==INT_MAX)
			break;

		// iterate the children of the node being checked to update the shortest path
		vector<vector<int>> nexts=g[check];
		int disFromStart=shortest[check];
		for (vector<int> next : nexts) {
			int node=next[0], w=next[1];
			if (isSel[node]) continue;
			shortest[node]=min(shortest[node], disFromStart+w);
		}

		// select the node
		isSel[check]=1;

		// look for the shortest path from start node
		vector<int> closestUnSel={-1,-1};
		for (int node=1; node<=n; node++) {
			if (!isSel[node]) {
				int w=shortest[node];
				if (closestUnSel[0]==-1)	
					closestUnSel={node,w};
				else {
					if (w<closestUnSel[1])
						closestUnSel = {node,w};
				}
			}
		}

		// loop
		check=closestUnSel[0];
	}


	return shortest[b];
}

int main() {
	cin>>n>>m;
	for (int i=0; i<m; i++) {
		int a,b,w; cin>>a>>b>>w;
		g[a].push_back({b,w});
		g[b].push_back({a,w});
	}
	int j,k; cin>>j>>k;
	int ans = dijkstra(j,k);
	cout << ans << endl;
}