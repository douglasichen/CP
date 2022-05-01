#include <bits/stdc++.h>
using namespace std;

int N,X,md=1e9+7;
vector<int> V,dp(1e6+1,-1);

int solve(int r, int last) {
	if (r==0) return 1;
	if (dp[r]!=-1) return dp[r];
	long long ways=0;
	for (int i : V) {
		if (i<last || r-i<0) continue;
		ways+=solve(r-i,i);
	}
	dp[r]=ways%md;
	return dp[r];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>X;
	V=vector<int>(N);
	for (int i=0; i<N; i++) cin>>V[i];
	int ans=solve(X,0);
	cout << ans << endl;
}