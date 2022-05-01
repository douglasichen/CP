#include <bits/stdc++.h>
using namespace std;

int N,M;
unordered_map<int,vector<int>> G;

vector<int> vis(21);
bool dfs(int root, int start, int dis) {
	vis[root]=1;
	for (int i : G[start]) {
		if (!vis[i]) {
			dfs(root,i,dis+1);
		}
		else {
			if(i==root && dis==)
		}
	}
}

bool solve() {
	for (int i=1; i<=N; i++) {
		if (dfs(i,i,0)) return 1;
	}
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	for (int i=0; i<N; i++) {
		int a,b; cin>>a>>b;	
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cout << (solve() ? "YES" : "NO") << endl;
}