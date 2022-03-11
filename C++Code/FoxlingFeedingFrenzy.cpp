#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, vector<vector<int>> v) {
	int needed=0;
	int extra=0;
	for (vector<int> b : v) {
		needed+=b[0];
		extra+=(b[1]-b[0]);
	}
	if (m-needed==0) return 1;
	if (m-needed<0) return 0;

	// otherwise...
	m-=needed;
	if (m-extra<0) return (1+m);
	
	// otherwise...
	return 1+extra;
}

int main() {
	int t; cin>>t;
	int ans[t];
	for (int i=0; i<t; i++) {
		int n,m; cin>>n>>m;
		vector<vector<int>> v(n,*(new vector<int>(2)));
		for (int o=0; o<n; o++)
			cin>>v[o][0]>>v[o][1];
		ans[i]=solve(n,m,v);
	}
	for (int i : ans) cout << i << endl;
}
