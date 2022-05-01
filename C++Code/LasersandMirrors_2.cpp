#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	freopen("lasers.in","r",stdin); 
	freopen("lasers.out","w",stdout); 

	int N; cin>>N;
	vector<int> L(2),B(2); cin>>L[0]>>L[1]>>B[0]>>B[1];
	vector<vector<int>> V(N);
	for (int i=0; i<N; i++) {
		vector<int> pos(2); cin>>pos[0]>>pos[1];
		V[i]=pos;
	}
	vector<bool> vis(N);
	deque<vector<int>> dq; dq.push_back({L[0],L[1],0});
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		if (back[0]==B[0] || back[1]==B[1]) {
			cout << back[2] << endl;
			return 0;
		}
		for (int i=0; i<N; i++) {
			if (!vis[i] && back[0]==V[i][0] || back[1]==V[i][1]) {
				vis[i]=1;
				dq.push_front({V[i][0],V[i][1],back[2]+1});
			}
		}
	}
	cout << -1 << endl;
}