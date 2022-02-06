#include <bits/stdc++.h>
using namespace std;

bool solve(int a, int b, int c) {
	return false;
}

int main() {
	int t; cin>>t;
	bool ans[t];
	for (int i=0; i<t; i++) {
		int a,b,c; cin>>a>>b>>c;
		ans[i]= solve(a,b,c);
	}
	for (bool i : ans) cout << (i ? "YES" : "NO") << endl;
}