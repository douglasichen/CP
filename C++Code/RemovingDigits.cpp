#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> dp(N+1,INT_MAX);
	dp[0]=0;
	for (int i=1; i<=N; i++) {
		string s=to_string(i);
		for (char c : s) {
			int num=c-'0';
			if (i-num<0) continue;
			dp[i]=min(dp[i],dp[i-num]+1);
		}
	}
	cout << dp[N] << endl;
}