#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	freopen("lasers.in","r",stdin); 
	freopen("lasers.out","w",stdout); 

	int N; cin>>N;
	vector<int> L(2),B(2); cin>>L[0]>>L[1]>>B[0]>>B[1];
	unordered_map<int,vector<int>> V,H;
	for (int i=0; i<N; i++) {
		int x,y; cin>>x>>y;
		V[x].push_back(y);
		H[y].push_back(x);
	}
	map<int,map<int,bool>> vis; vis[L[0]][L[1]]=1;
	deque<vector<int>> dq; dq.push_back({L[0],L[1],0});
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		if (back[0]==B[0] || back[1]==B[1]) {
			cout << back[2] << endl;
			return 0;
		}
		for (int y : V[back[0]]) {
			if (!vis[back[0]][y]) {
				vis[back[0]][y]=1;
				dq.push_front({back[0],y,back[2]+1});
			}
		}
		for (int x : H[back[1]]) {
			if (!vis[x][back[1]]) {
				vis[x][back[1]]=1;
				dq.push_front({x,back[1],back[2]+1});
			}
		}
	}
	cout << -1 << endl;
}