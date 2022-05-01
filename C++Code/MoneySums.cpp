#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N);
	vector<bool> dp(1e5+1);
	for (int i=0; i<N; i++) {
		cin>>V[i];
	}
	for (int num : V) {
		vector<bool> oDp=dp;
		for (int i=1; i<=1e5; i++) {
			if (oDp[i]) dp[i+num]=1;
		}
		dp[num]=1;
	}
	int cnt=0;
	for (int i=0; i<=1e5; i++) {
		cnt+=dp[i];
	}
	cout << cnt << endl;
	for (int i=0; i<=1e5; i++) {
		if (dp[i]) cout << i << ' ';
	}
	cout << endl;
}