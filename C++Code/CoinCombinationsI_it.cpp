#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,X; cin>>N>>X;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];

	int md=1e9+7;
	vector<int> dp(X+1);
	dp[0]=1;
	for (int i=1; i<=X; i++) {
		long long ways=0;
		for (int c : V) {
			if (i-c<0) continue;
			ways+=dp[i-c];
		}
		dp[i]=ways%md;
	}
	cout << dp[X] << endl;
}