#include <bits/stdc++.h>
using namespace std;

int N,M,D;
vector<vector<int>> g, span, costs;

long long firstCost=0, spanCost=0;
vector<vector<bool>> firstActive, spanActive;
vector<vector<int>> firstActives, spanActives;

void solveSpan() {
	unordered_map<int,bool> isSel;
	vector<int> sels = {1};
	isSel[1]=1;
	
	while (sels.size()<N) {
		// closest unSel from all sels
		vector<int> close = {0,0,INT_MAX};	// node a, node b, cost
		for (int a : sels) {
			vector<int> children=g[a];
			for (int b : children) {
				int cost=costs[a][b], bestCost=close[2];
				if (!isSel[b])
					if (cost<bestCost)
						close={a,b,cost};
					else if (cost==bestCost && firstActive[a][b]) {		// closest min span tree from initial
						close={a,b,cost};
					}
			}
		}
		
		// closest from selected
		int a=close[0], b=close[1], cost=close[2];
		isSel[b]=1;
		sels.push_back(b);

		// span[a].push_back(b);
		// span[b].push_back(a);
		spanCost+=(long long)cost;

		// span active matrix
		spanActive[a][b]=1;
		spanActive[b][a]=1;
		spanActives.push_back({a,b});
	}
}

int main() {
	cin>>N>>M>>D;
	g=*(new vector<vector<int>>(N+1));
	// span=g;
	costs=*(new vector<vector<int>>(N+1, *(new vector<int>(N+1))));

	firstActive=*(new vector<vector<bool>>(N+1,*(new vector<bool>(N+1))));
	spanActive=firstActive;


	vector<int> exp = {0,0,0};
	// input
	for (int i=0; i<M; i++) {
		int A,B,C; cin>>A>>B>>C;
		g[A].push_back(B);
		g[B].push_back(A);

		// cost matrix
		costs[A][B]=C;
		costs[B][A]=C;
		
		// calc most expensive
		if (C>exp[3])
			exp={A,B,C};
		
		// activated already
		if (i+1<=N-1) {
			firstCost+=C;
			firstActive[A][B]=1;
			firstActive[B][A]=1;
			firstActives.push_back({A,B});
		}
	}

	// apply cost reduction on most expensive
	// int a=exp[0], b=exp[1], c=exp[2];
	// int newCost=costs[a][b]-D;
	// costs[a][b]=max(newCost,0);
	// costs[b][a]=max(newCost,0);

	// // if the most expensive is one of the activated, deduct the first cost
	// if (firstActive[a][b])
	// 	firstCost=max(firstCost-D,0LL);

	solveSpan();

	// cout << firstCost << " vs " << spanCost << endl;

	// already min tree
	if (firstCost==spanCost) {
		cout << 0 << endl;
		return 0;
	}

	
	// need on, need off
	int needOn=0, needOff=0;
	for (vector<int> active : firstActives) {
		if (!spanActive[active[0]][active[1]])
			needOff++;
	}
	for (vector<int> active : spanActives) {
		if (!firstActive[active[0]][active[1]])
			needOn++;
	}

	// days
	int ans=max(needOff,needOn);
	cout << ans << endl;
}