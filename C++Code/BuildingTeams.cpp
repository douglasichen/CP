#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N,M; cin>>N>>M;
	vector<vector<int>> G(N+1);
	for (int i=0; i<M; i++) {
		int a,b; cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> ans(N+1);
	vector<bool> vis(N+1);
	for (int start=1; start<=N; start++) {
		if (!vis[start]) {
			vis[start]=1;
			deque<int> dq;
			dq.push_back(start);
			while (!dq.empty()) {
				int back=dq.back(); dq.pop_back();
				for (int i : G[back]) {
					if (!vis[i]) {
						vis[i]=1;
						dq.push_front(i);
						ans[i]=!ans[back];
					}
				}
			}
		}
	}
	for (int i=1; i<=N; i++) {
		for (int o : G[i]) {
			if (ans[i]==ans[o]) {
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
		}
	}
	for (int i=1; i<=N; i++) cout << ans[i]+1 << ' ';
	cout << endl;
}