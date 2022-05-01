#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int A,B; cin>>A>>B;
	if (A>B) swap(A,B);
	vector<vector<int>> dp(A+1,vector<int>(B+1,-1));
	for (int i=1; i<=A; i++) dp[i][1]=i-1;
	for (int i=1; i<=B; i++) dp[1][i]=i-1;
	for (int y=2; y<=A; y++) {
		for (int x=2; x<=B; x++) {
			if (dp[y][x]!=-1) continue;
			if (y==x) {
				dp[y][x]=0;
				continue;
			}
			int yy=y,xx=x;
			if (yy>xx) swap(yy,xx);

			int mn=INT_MAX;
			for (int i=1; i<yy; i++) mn=min(mn,dp[i][xx]+dp[yy-i][xx]+1);
			for (int i=1; i<xx; i++) mn=min(mn,dp[yy][i]+dp[yy][xx-i]+1);
			dp[yy][xx]=mn;
			dp[y][x]=mn;
		}
	}
	cout << dp[A][B] << endl;
}