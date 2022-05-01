#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int md=1e9+7;
	int N,M; cin>>N>>M;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];

	vector<vector<long long>> dp(N,vector<long long>(M+1));
	if (V[0]==0) fill(dp[0].begin()+1,dp[0].end(),1);
	else dp[0][V[0]]=1;
	for (int i=1; i<N; i++) {
		for (int v=1; v<=M; v++) {
			if (V[i]!=0 && v!=V[i]) continue;
			dp[i][v]+=dp[i-1][v];
			if (v-1>0) dp[i][v]+=dp[i-1][v-1];
			if (v+1<=M) dp[i][v]+=dp[i-1][v+1];
			dp[i][v]%=md;
		}
	}
	long long ans=0;
	for (long long i : dp[N-1]) {
		ans+=i;
		ans%=md;
	}
	for (int i=0; i<N; i++) {
		if (V[i]>M || (i>0 && V[i]!=0 && V[i-1]!=0 && abs(V[i]-V[i-1])>1)) {
			ans=0;
			break;
		}
	}
	cout << ans << endl;
}