#include <bits/stdc++.h>
using namespace std;

int N,T;
vector<int> V,dp(1e6+1,-1);
int md=1e9+7;

long long solve(int X) {
	// return number of ways to reduce X -> 0
	if (X==0) return 1;
	if (dp[X]!=-1) return dp[X];
	long long ways=0;
	for (int i : V) {
		if (X-i<0) continue;
		ways+=solve(X-i);
	}
	dp[X]=ways%md;
	return dp[X];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>T;
	V=vector<int>(N);
	for (int i=0; i<N; i++) cin>>V[i];
	
	long long ans=solve(T);
	cout << ans << endl;
}