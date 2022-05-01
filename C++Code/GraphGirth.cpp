#include <bits/stdc++.h>
using namespace std;

int ans=INT_MAX;
vector<vector<int>> G(2501);
vector<bool> vis(2501);
vector<int> dis(2501,0);

void dfs(int from, int behind) {
	vis[from]=1;
	// cout << from << endl;
	for (int i : G[from]) {
		if (i!=behind) {
			if (vis[i]) {
				int nw=dis[from]-dis[i]+1;
				if (nw>2) ans=min(ans,nw);
			}
			else {
				dis[i]=dis[from]+1;
				vis[i]=1;
				dfs(i,from);
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int start=1;
	int N,M; cin>>N>>M;
	for (int i=0; i<M; i++) {
		int a,b; cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
		start=a;
	}
	for (int i=1; i<=N; i++) {
		dfs(i,0);
		vis=vector<bool>(2501);
		dis=vector<int>(2501);
	}

	// for (int i=1; i<=N; i++) cout << dis[i] << ' '; cout << endl;
	if (ans==INT_MAX) cout << -1 << endl;
	else cout << ans << endl;
}