#include <bits/stdc++.h>
using namespace std;

int solve(int l, int r, int a) {
	int m=r/a;
	int big=m*a-1;
	if (big>=l) {
		int ans1=big/a + big%a, ans2=r/a + r%a;
		return max(ans1,ans2);
	}
	else {
		return r/a + r%a;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	int ans[T];
	for (int i=0; i<T; i++) {
		int l,r,a; cin>>l>>r>>a;
		ans[i]=solve(l,r,a);
	}
	for (int i : ans) cout << i << endl;
}