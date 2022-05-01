#include <bits/stdc++.h>
using namespace std;

long long solve(int a, int b) {
	if (a==0) return 1;
	return a+2*b+1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	vector<long long> ans(T);
	for (int i=0; i<T; i++) {
		int a,b; cin>>a>>b;
		ans[i]=solve(a,b);
	}	
	for (long long i : ans) cout << i << endl;
}