#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> dp;
long long md=1e9+7;

long long solve(int need) {
	if (need==0) return 1;
	if (dp[need]!=0) return dp[need];
	long long ways=0;
	for (int i=1; i<=min(need,6); i++) {
		ways+=solve(need-i);
	}
	dp[need]=ways%md;
	return dp[need];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	dp=vector<int>(N+1);
	long long ans=solve(N);
	cout << ans << endl;
}