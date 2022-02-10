#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, vector<char> v) {
	if (n==1) return k;
	int current=0;
	for (int i=0; i<n/2; i++) {
		if (v[i]!=v[n-1-i]) current++;
	}
	// cout << "k: " << k << endl;
	// cout << "cur: " << current << endl;
	return abs(k-current);
}

int main() {
	int t; cin>>t;
	vector<int> ans(t);
	for (int i=0; i<t; i++) {
		int n, k; cin>>n>>k;
		vector<char> v(n);
		for (int i=0; i<n; i++) cin>>v[i];
		ans[i]=solve(n,k,v);
	}
	for (int i=0; i<t; i++) {
		cout << "Case #" << i+1 << ": " << ans[i] << endl;
	}
}