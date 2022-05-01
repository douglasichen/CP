#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> G;

vector<int> frm,ans;
vector<bool> vis;

int start=0,last=0;

bool dfs(int node, int behind) {
	frm[node]=behind;
	vis[node]=1;
	for (int i : G[node]) {
		if (i==behind) continue;
		if (vis[i]) {
			last=node;
			start=i;
			return 1;
		}
		if (!vis[i]) {
			vis[i]=1;
			if (dfs(i,node)) return 1;
		}
		
	}
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M;
	G=vector<vector<int>>(N+1);
	frm=vector<int>(N+1);
	vis=vector<bool>(N+1);
	for (int i=0; i<M; i++) {
		int a,b; cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i=1; i<=N; i++) {
		if (!vis[i] && dfs(i,0)) {
			int at=last;
			vector<int> v;
			while (at!=start) {
				v.push_back(at);
				at=frm[at];
			}
			v.push_back(start);
			v.push_back(last);
			cout << v.size() << endl;
			for (int i : v) cout << i << ' ';
			cout << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}