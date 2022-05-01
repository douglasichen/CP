#include <bits/stdc++.h>
using namespace std;

long long N;
vector<bool> C;
vector<vector<int>> T;
vector<vector<long long>> adj;

void bfs(long long &ans) {
	vector<bool> vis(N+1); vis[1]=1;
	deque<vector<int>> dq; // node A, prev;
	dq.push_back({1,0});
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		if (back[1]) {
			vector<long long> a=adj[back[0]], b=adj[back[1]];
			if (C[back[0]]) b[0]--;
			else b[1]--;
			if (C[back[1]]) a[0]--;
			else a[1]--;
			if (C[back[0]] && C[back[1]]) {
				ans-=a[1]*b[1];
			}
			else if (C[back[0]] || C[back[1]]) {
				ans-=a[0]*b[1]+a[1]*b[0];
			}
			else {
				ans-=a[0]*b[0];
			}
		}
		for (int i : T[back[0]]) {
			if (!vis[i]) {
				dq.push_front({i,back[0]});
				vis[i]=1;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	C=vector<bool>(N+1);
	T=vector<vector<int>>(N+1);
	adj=vector<vector<long long>>(N+1,{0LL,0LL});
	for (int i=1; i<=N; i++) {
		char c; cin>>c;
		C[i]=c=='B';
	}
	for (int i=0,a,b; i<N-1; i++) {
		cin>>a>>b;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	long long ans=N*(N-1)/2-(N-1);
	for (int i=1; i<=N; i++) {
		for (int o : T[i]) {
			if (C[o]) adj[i][0]++;
			else adj[i][1]++;
		}
		ans-=adj[i][1]*adj[i][0];
		if (C[i]) {
			if (adj[i][1]>=2) ans-=adj[i][1]*(adj[i][1]-1)/2LL;
		}
		else {
			if (adj[i][0]>=2) ans-=adj[i][0]*(adj[i][0]-1)/2LL;
		}
	}
	bfs(ans);
	cout << ans << endl;
}