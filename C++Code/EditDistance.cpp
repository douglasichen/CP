#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	string A,B; cin>>A>>B;
	int N=A.size(),M=B.size();
	vector<vector<int>> dp(N+1,vector<int>(M+1));
	for (int i=0; i<=N; i++) dp[i][0]=i;
	for (int i=0; i<=M; i++) dp[0][i]=i;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=M; j++) {
			int y=i-1,x=j-1;
			int del=dp[i][j-1]+1,add=dp[i-1][j]+1,change=dp[i-1][j-1]+(A[y]!=B[x]);
			dp[i][j]=min(del,min(add,change));
		}
	}
	cout << dp[N][M] << endl;
}