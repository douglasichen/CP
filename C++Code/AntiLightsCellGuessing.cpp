#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m) {
	if (min(n,m)==1) {
		if (max(n,m)==3 || max(n,m)==2) return 1;
		if (max(n,m)==1) return 0;
	}
	if 
}

int main() {
	int t; cin>>t;
	int ans[t];
	for (int i=0; i<t; i++) {
		int n,m; cin>>n>>m;
		ans[i]=solve(n,m);
	}
	for (int i : ans) cout << i << endl;
}