#include <bits/stdc++.h>
using namespace std;

unsigned long long dp[100000];

unsigned long long fib(int n) {
	if (n==0) return 0;
	if (n<=2) return 1;
	if (dp[n]!=0) return dp[n];
	dp[n]=fib(n-1) + fib(n-2);
	return dp[n];
}



int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	memset(dp, 0, sizeof dp);
	cout << fib(100) << endl;
}