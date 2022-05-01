#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N,M; cin>>N>>M;
	vector<vector<vector<int>>>	G(N+1);
	for (int i=0; i<M; i++) {
		int a,b,c; cin>>a>>b>>c;
		G[a].push_back({b,c});
	}
	vector<bool> vis(N+1);
	vector<long long> D(N+1,LLONG_MAX);
	auto cmp=[&](vector<long long> &a, vector<long long> &b){return a[0]>b[0];};
	priority_queue<vector<long long>,vector<vector<long long>>,decltype(cmp)> pq(cmp);
	pq.push({0,1});
	D[1]=0;
	while (!pq.empty()) {
		int top=pq.top()[1]; pq.pop();
		if (vis[top]) continue;
		vis[top]=1;
		for (vector<int> nxt : G[top]) {
			int node=nxt[0],cost=nxt[1];
			if (D[top]+cost<D[node]) {
				D[node]=D[top]+cost;
				pq.push({D[node],node});
			}
		}
	}
	for (int i=1; i<=N; i++) cout << D[i] << ' ';
	cout << endl;
}