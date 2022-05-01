#include <bits/stdc++.h>
using namespace std;

vector<int> V,dp(1e6+1);

int solve(int X) {
	if (X==0) return 0;
	if (dp[X]) return dp[X];
	int mn=INT_MAX;
	for (int i : V) {
		if (X-i<0) break;
		int result=solve(X-i);
		if (result==INT_MAX) continue;
		mn=min(mn,result+1);
	}
	dp[X]=mn;
	return mn;
}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,X; cin>>N>>X;
	V=vector<int>(N);
	for (int i=0; i<N; i++) cin>>V[i];
	sort(V.begin(),V.end());
	
	int ans=solve(X);
	if (ans==INT_MAX) cout << -1 << endl;
	else cout << ans << endl;
}