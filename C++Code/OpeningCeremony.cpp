#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int a[3],b[3];
	for (int i=0; i<3; i++) cin>>a[i];
	int sum=0;
	for (int i=0; i<3; i++) {
		int inp; cin>>inp;
		b[i]=inp;
		sum+=inp;
	}

	int ans=0;
	for (int i=0; i<3; i++) {
		ans += a[i]*b[i];
	}
	cout << sum << ' ' << ans << endl;
}