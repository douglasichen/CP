#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll K; cin>>K;
	vector<int> ans;
	vector<ll> dp(1e5+1);
	for (int i=1; i<=1e5; i++) {
		dp[i]=1+dp[i-1];
		if (K-dp[i]<0) break;
		K-=dp[i];
		cout << dp[i] << ' ';
		ans.push_back(i);
	}
	cout << endl;
	int last=ans.back();
	for (int i=last; i; i--)
		while (K-dp[i]>=0) 
			K-=dp[i], 
			ans.push_back(i);

	cout << ans.size() << endl;
	for (int i : ans) cout << i << ' '; cout << endl;

}