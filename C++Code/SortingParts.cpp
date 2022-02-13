#include <bits/stdc++.h>
using namespace std;

bool solve(int n, vector<int> v) {
	int mx=v[0];
	stack<int> s; 	// element and min 
	for (int i=n-1; i>=1; i--) {
		int mn = (s.empty() ? v[i] : min(s.top(),v[i]));	// the miniumum is the top of stack vs new elem
		s.push(mn);
	}

	for (int i=1; i<=n-1; i++) {
		mx=max(mx,v[i]);
		int mn=s.top();
		if (mn<mx) return 1;
		s.pop();
	}

	return 0;
}

int main() {
	int t; cin>>t;
	bool ans[t];
	for (int i=0; i<t; i++) {
		int n; cin>>n;
		vector<int> v(n);
		for (int o=0; o<n; o++) {
			cin>>v[o];
		}
		ans[i]=solve(n,v);
	}
	for (bool i : ans) cout << (i ? "YES" : "NO") << endl; 
}