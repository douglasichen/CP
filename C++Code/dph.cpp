#include <bits/stdc++.h>
using namespace std;

void solve() {

}

#define ll long long

long long md=1e9+7;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int H,W; cin>>H>>W;
	vector<vector<bool>> wall(H+1,vector<bool>(W+1));
	vector<vector<ll>> dp(H+1,vector<ll>(W+1));
	char c;
	for (int y=1; y<=H; y++) {
		for (int x=1; x<=W; x++) {
			cin>>c;
			wall[y][x]=c=='#';
		}
	}
	dp[1][1]=1;
	for (int y=1; y<=H; y++) {
		for (int x=1; x<=W; x++) {
			if (!wall[y][x]) {
				dp[y][x]+=dp[y-1][x]+dp[y][x-1];
				dp[y][x]%=md;
			}
		}
	}
	cout << dp[H][W] << endl;
}