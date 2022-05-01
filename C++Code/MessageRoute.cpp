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
	deque<vector<int>> dq; // node, dis
	dq.push_back({1,0});
	vis[1]=1;
	vector<int> froms(N+1);
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		int node=back[0],dis=back[1];
		for (int newNode : G[node]) {
			if (!vis[newNode]) {
				dq.push_front({newNode,dis+1});
				vis[newNode]=1;
				froms[newNode]=node;
				if (newNode==N) {
					cout << dis+2 << endl;
					vector<int> route;
					int at=newNode;
					while (at!=0) {
						route.push_back(at);
						at=froms[at];
					}
					for (int i=route.size()-1; i>=0; i--) cout << route[i] << ' ';
					cout << endl;
					return 0;
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}
