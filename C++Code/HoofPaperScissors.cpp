#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("hps.in","r",stdin);
	freopen("hps.out","w",stdout); 

	int N,K; cin>>N>>K;
	vector<int> V(N+1);
	vector<vector<int>> win={
		{0,0,1},
		{1,0,0},
		{0,1,0}
	};
	for (int i=1; i<=N; i++) {
		char inp; cin>>inp;
		if (inp=='H') inp=0;
		else if (inp=='P') inp=1;
		else inp=2;
		V[i]=inp;
	}
	vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(K+1,vector<int>(3)));
	for (int i=1; i<=N; i++) {
		for (int o=0; o<3; o++) {
			dp[i][0][o]=dp[i-1][0][o]+win[o][V[i]];
		}
	}
	for (int x=1; x<=N; x++) {
		for (int y=1; y<=K; y++) {
			int lessK=max(dp[x-1][y-1][0],max(dp[x-1][y-1][1],dp[x-1][y-1][2]));
			for (int z=0; z<3; z++) {
				dp[x][y][z]=max(lessK,dp[x-1][y][z])+win[z][V[x]];
			}
		}
	}
	

	int ans=0;
	for (int i : dp[N][K]) ans=max(ans,i);
	cout << ans << endl;
}