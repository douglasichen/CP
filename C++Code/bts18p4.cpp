#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;
vector<bool> gd,V;
vector<vector<int>> G;

vector<int> bfs(int at, bool app) {
	vector<int> ret={0,1};
	deque<vector<int>> dq;
	vector<bool> vis(N+1);
	vis[at]=1;
	if (app) V[at]=1;
	dq.push_back({at,1});
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		if (back[1]>ret[1]) ret=back;
		for (int i : G[back[0]]) {
			if (!vis[i]) {
				vis[i]=1;
				if (app) V[i]=1;
				dq.push_front({i,back[1]+1});
			}
		}
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	gd=vector<bool>(N+1);
	V=vector<bool>(N+1);
	G=vector<vector<int>>(N+1);
	ll Y;
	for (int i=1; i<=N; i++) {
		cin>>Y;
		ll s=4*Y+1,p=sqrt(s);
		gd[i]=(p*p==s) && (p%2);
	}
	for (int i=0,a,b; i<N-1; i++) {
		cin>>a>>b;
		if (gd[a] && gd[b]) G[a].push_back(b),G[b].push_back(a);
	}
	int ans=0;
	for (int i=1; i<=N; i++) {
		if (gd[i] && !V[i]) ans=max(ans,bfs(bfs(i,0)[0],1)[1]);
	}
	cout << ans << endl;
}