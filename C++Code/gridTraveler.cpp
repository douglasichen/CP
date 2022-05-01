#include <bits/stdc++.h>
using namespace std;

int N,M;
// int dp[1]

void solve(int n, int m, vector<int> sz) {
	if (n>N || m>M) return 0;
	if (n==1 || m==1) return 1;
	return solve()
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M;
	cout << solve(N,M,{N,M}) << endl;
}