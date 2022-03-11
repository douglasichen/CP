#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int t; cin>>t;
	int ans[t];
	for (int i=0; i<t; i++)  {
		int n,m; cin>>n>>m;
		int tc=0;
		for (int i=0; i<n; i++) {
			int inp; cin>>inp;
			tc+=inp;
		}
		// cout << "T: " << tc << " " << m << endl;
		ans[i]=tc%m;
	}
	for (int i=1; i<=t; i++) {
		cout << "Case #" << i << ": " << ans[i-1] << endl;
	}
}