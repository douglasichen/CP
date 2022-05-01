#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<vector<pair<int,int>>> G(N+1);
	for (int i=0; i<M; i++) {
		int a,b,c; cin>>a>>b>>c;
		G[a].push_back({c,b});
		G[b].push_back({c,a});
	}
	
	vector<int> frm(N+1);
	vector<bool> vis(N+1);
	vector<long long> D(N+1,1e14); D[1]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; pq.push({0,1});
	while (!pq.empty()) {
		pair<int,int> top=pq.top(); pq.pop();
		if (vis[top.second] || D[top.second]<top.first) continue;
		vis[top.second]=1;
		for (pair<int,int> p : G[top.second]) {
			long long cost=top.first+p.first;
			if (!vis[p.second] && D[p.second]>cost) {
				D[p.second]=cost;
				pq.push({cost,p.second});
				frm[p.second]=top.second;
			}
		}
	}

	if (D[N]==1e14) cout << "-1" << endl;
	else {
		stack<int> path;
		int at=N;
		while (frm[at]) {
			path.push(at);
			at=frm[at];
		}
		path.push(1);
		while (!path.empty()) {
			cout << path.top() << ' ';
			path.pop();
		}
		cout << endl;
	}
}