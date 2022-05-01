#include <bits/stdc++.h>
using namespace std;

long long solve(int V, int K, vector<vector<vector<int>>> G, int A, int B) {
	vector<bool> vis(V+1);
	vector<long long> D(V+1,LLONG_MAX);
	D[A]=0;
	auto comp = [&](int &a, int &b) {
		return D[a]>D[b];
	};
	priority_queue<int,vector<int>,decltype(comp)> pq(comp);
	pq.push(A);
	while (!pq.empty()) {
		int top=pq.top(); pq.pop();
		vis[top]=1;
		if (top==B) break;
		for (vector<int> nxt : G[top]) {
			int node=nxt[0],cost=nxt[1];
			D[node]=min(D[node],D[top]+cost);
			if (!vis[node]) pq.push(node);
		}
	}
	return D[B];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	long long ans[T];
	for (int i=0; i<T; i++) {
		int V,K; cin>>V>>K;
		vector<vector<vector<int>>> G(V+1);
		for (int o=0; o<K; o++) {
			int a,b,c; cin>>a>>b>>c;
			G[a].push_back({b,c});
			// G[b].push_back({a,c});
		}
		int A,B; cin>>A>>B;
		ans[i]=solve(V,K,G,A,B);
	}
	for (long long i : ans) {
		if (i==LLONG_MAX) cout << "NO" << endl;
		else cout << i << endl;
	}
}