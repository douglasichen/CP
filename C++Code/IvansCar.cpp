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
	int A,B; cin>>A>>B;
	vector<bool> vis(N+1);
	deque<vector<int>> dq;
	vis[A]=1;
	dq.push_back({A,0});
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		if (back[0]==B) {
			cout << max(back[1]-1,0) << endl;
			return 0;
		}
		for (int i : G[back[0]]) {
			if (!vis[i]) {
				vis[i]=1;
				dq.push_front({i,back[1]+1});
			}
		}
	}
}