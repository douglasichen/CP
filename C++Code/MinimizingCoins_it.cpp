#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,X; cin>>N>>X;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];

	vector<int> dp(X+1);
	for (int i=1; i<=X; i++) {
		int mn=INT_MAX;
		for (int c : V) {
			if (i-c<0) continue;
			int res=dp[i-c];
			if (res==INT_MAX) continue;
			mn=min(mn,res+1);
		}
		dp[i]=mn;
	}
	if (dp[X]==INT_MAX) cout << -1 << endl;
	else cout << dp[X] << endl;
}