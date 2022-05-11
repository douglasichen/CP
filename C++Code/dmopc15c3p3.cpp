#include <bits/stdc++.h>
using namespace std;

int N,M;
bool ans=0;
vector<vector<int>> G;
vector<bool> vis;
vector<int> dis;

void dfs(int at) {
	vis[at]=1;
	for (int i : G[at]) {
		if (!vis[i]) {
			dis[i]=dis[at]+1;
			dfs(i);
		}
		else {
			if (dis[at]+1-dis[i]==6) ans=1;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	G=vector<vector<int>>(N+1);
	vis=vector<bool>(N+1);
	for (int i=0,a,b; i<M; i++) {
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i=1; i<=N; i++) {
		dis=vector<int>(N+1);
		if (!vis[i]) dfs(i);
	}
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}