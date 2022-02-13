#include <bits/stdc++.h>
using namespace std;

int t,n;
unordered_map<size_t,int> name2Ind;	// city name to index;

unordered_map<int,vector<vector<int>>> g; // city num -> (city num, cost)

int solve(int a, int b) {
	unordered_map<int,bool> isSel;
	
	int check=a;
	vector<int> shortest(n+1,INT_MAX);
	shortest[check]=0;
	
	while (check>0) {
		// update children
		int disFromStart=shortest[check];

		if (disFromStart==INT_MAX)
			break;

		vector<vector<int>> children=g[check];
		for (vector<int> childData : children) {
			int child=childData[0], childW=childData[1];
			if (!isSel[child])
				shortest[child]=min(shortest[child], disFromStart+childW);
		}

		// select
		isSel[check]=1;

		// closest unselected node from start
		vector<int> close={-1,-1};
		for (int i=1; i<=n; i++) {
			int node=i;
			int dis=shortest[node];
			if (!isSel[node]) {
				if (close[0]==-1) close={node,dis};
				else {
					if (dis<close[1])	
						close={node,dis};
				}
			}
		}

		check=close[0];
	}
	
	return shortest[b];
}

int main() {
	hash<string> h;
	cin>>t;
	for (int i=0; i<t; i++) {
		cin>>n;
		for (int i=1; i<=n; i++) {
			string name; cin>>name;
			name2Ind[h(name)]=i;

			int m; cin>>m;
			for (int k=0; k<m; k++) {
				int to,cost; cin>>to>>cost;
				g[i].push_back({to,cost});
			}
		}

		int m; cin>>m;
		vector<int> ans(m);
		for (int i=0; i<m; i++) {
			string from,to; cin>>from>>to;
			int a=name2Ind[h(from)],b=name2Ind[h(to)];
			ans[i]=solve(a,b);
		}
		
		for (int i : ans)
			cout << i << endl;
		
		name2Ind.clear();
		g.clear();
	}
}