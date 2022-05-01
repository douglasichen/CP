#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int md=1e9+7;
	int N,X; cin>>N>>X;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];

	vector<int> dp(X+1);
	dp[0]=1;
	for (int c : V) {
		for (int i=1; i<=X; i++) {
			if (i-c<0) continue;
			dp[i]+=dp[i-c];
			dp[i]%=md;
		}
	}
	cout << dp[X] << endl;
}