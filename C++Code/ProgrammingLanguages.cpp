#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, int v[][2]) {
	if ((a==v[0][0] || a==v[0][1]) && (b==v[0][0] || b==v[0][1])) return 1;
	if ((a==v[1][0] || a==v[1][1]) && (b==v[1][0] || b==v[1][1])) return 2;
	return 0;
}

int main() {
	int t; cin>>t;
	int ans[t];
	for (int i=0; i<t; i++) {
		int a,b; cin>>a>>b;
		int v[2][2]; cin>>v[0][0]>>v[0][1]>>v[1][0]>>v[1][1];
		ans[i]=solve(a,b,v);
	}
	for (int i=0; i<t; i++) cout << ans[i] << endl;
}