#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int D,N; cin>>D>>N;
	vector<int> V(N), dp(10000,10000);
	for (int i=0; i<N; i++) cin>>V[i];
	dp[0]=0;
	for (int i=0; i<D; i++) {
		for (int o : V)
			if (i+o<=D)
				dp[i+o]=min(dp[i+o],dp[i]+1);
	}
	int ans=dp[D];
	if (ans==10000) ans=0;
	if (ans) cout << "Roberta wins in " << ans << " strokes." << endl;
	else cout << "Roberta acknowledges defeat." << endl;
}