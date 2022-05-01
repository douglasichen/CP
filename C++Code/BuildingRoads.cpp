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

	vector<bool> vis(N+1);
	vector<int> islands;
	for (int start=1; start<=N; start++) {
		if (!vis[start]) {
			islands.push_back(start);
			deque<int> dq;
			vis[start]=1;
			dq.push_back(start);
			while (!dq.empty()) {
				int back=dq.back(); dq.pop_back();
				for (int i : G[back]) {
					if (!vis[i]) {
						dq.push_front(i);
						vis[i]=1;
					}
				}
			}
		}
	}
	cout << islands.size()-1 << endl;
	for (int i=1; i<islands.size(); i++) {
		cout << islands[i] << ' ' << islands[0] << endl;
	}
}