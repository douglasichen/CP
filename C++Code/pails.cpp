#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("pails.in","r",stdin); 
	freopen("pails.out","w",stdout); 

	int ans=INT_MAX;
	int X,Y,K,M; cin>>X>>Y>>K>>M;
	vector<vector<bool>> vis(101,vector<bool>(101)); vis[0][0]=1;
	deque<vector<int>> dq; dq.push_back({0,0,0});
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		// for (int i : back) cout << i << ' ';
		// cout << endl;

		int sm=back[0]+back[1];
		ans=min(ans,abs(M-sm));

		if (back[2]==K) {
			continue;
		}
		if (!vis[X][back[1]]) {
			vis[X][back[1]]=1;
			dq.push_front({X,back[1],back[2]+1});
		}
		if (!vis[back[0]][Y]) {
			vis[back[0]][Y]=1;
			dq.push_front({back[0],Y,back[2]+1});
		}
		if (!vis[0][back[1]]) {
			vis[0][back[1]]=1;
			dq.push_front({0,back[1],back[2]+1});
		}
		if (!vis[back[0]][0]) {
			vis[back[0]][0]=1;
			dq.push_front({back[0],0,back[2]+1});
		}
		int pA=min(X-back[0],back[1]), pB=min(Y-back[1],back[0]);
		if (!vis[back[0]+pA][back[1]-pA]) {
			vis[back[0]+pA][back[1]-pA]=1;
			dq.push_front({back[0]+pA,back[1]-pA,back[2]+1});
		}
		if (!vis[back[0]-pB][back[1]+pB]) {
			vis[back[0]-pB][back[1]+pB]=1;
			dq.push_front({back[0]-pB,back[1]+pB,back[2]+1});
		}
	}
	cout << ans << endl;

}