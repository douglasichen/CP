#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<vector<char>> V(N+1,vector<char>(N+1));	
	for (int y=1; y<=N; y++) {
		for (int x=1; x<=N; x++) {
			cin>>V[y][x];
		}
	}

	int md=1e9+7;
	vector<vector<long long>> dp(N+1,vector<long long>(N+1));
	dp[1][1]=V[1][1]!='*';
	for (int y=1; y<=N; y++) {
		for (int x=1; x<=N; x++) {
			if (V[y][x]=='*' || (y==1 && x==1)) continue;
			dp[y][x]=(dp[y-1][x]+dp[y][x-1])%md;
		}
	}
	cout << dp[N][N] << endl;
}