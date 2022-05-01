#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,X; cin>>N>>X;
	vector<int> H(N),S(N);
	for (int i=0; i<N; i++) cin>>H[i];
	for (int i=0; i<N; i++) cin>>S[i];

	vector<int> dp(X+1);	// max pages you can get at that price
	for (int i=0; i<N; i++) {
		vector<int> oldDp=dp;
		for (int mon=1; mon<=X; mon++) {
			int cost=H[i], pages=S[i], left=mon-cost;
			if (left<0) continue;
			dp[mon]=max(dp[mon],oldDp[left]+pages);
		}
	}
	// cout << endl;
	// for (int i : dp) cout << i << ' ';
	// cout << endl;

	int ans=0;
	for (int i : dp) ans=max(ans,i);
	cout << ans << endl;
}