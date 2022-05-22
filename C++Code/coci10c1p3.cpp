#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K; cin>>K;
	int at=1,sm=0,e=1;
	while (sm+at*2<K) {
		at*=2;
		sm+=at;
		e++;
	}
	K-=sm;
	K-=1;
	// cout << K << endl;

	string ans="";
	for (int i=0; i<e; i++) {
		if (K&1) ans+="7";
		else ans+="4";
		K>>=1;
	}
	for (int i=e-1; i>=0; i--) cout << ans[i];
	cout << endl;
}