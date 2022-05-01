#include <bits/stdc++.h>
using namespace std;

const long long INF=1e18;
int A,B,P,N,M;
vector<vector<int>> G;

void bfs(int start, vector<long long> &dis, long long step) {
	vector<bool> vis(N+1); vis[start]=1;
	deque<int> dq; dq.push_back(start);
	while (!dq.empty()) {
		int back=dq.back(); dq.pop_back();
		for (int i : G[back]) {
			if (!vis[i]) {
				vis[i]=1;
				dis[i]=dis[back]+step;
				dq.push_front(i);
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("piggyback.in","r",stdin); 
	freopen("piggyback.out","w",stdout); 
	
	cin>>A>>B>>P>>N>>M;
	G=vector<vector<int>>(N+1);
	for (int i=0; i<M; i++) {
		int a,b; cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<long long> goalDis(N+1),aDis(N+1),bDis(N+1),dis(N+1);
	bfs(N,goalDis,min(P,A+B));
	bfs(1,aDis,A);
	bfs(2,bDis,B);
	for (int i=1; i<=N; i++) dis[i]=aDis[i]+bDis[i]+goalDis[i];
	long long ans=INF;
	for (int i=1; i<=N; i++) ans=min(ans,dis[i]);
	cout << ans << endl;
	
}