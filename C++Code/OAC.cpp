#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N; cin>>N;
	vector<int> V(N);
	for (int i=0; i<N; i++) {
		cin>>V[i];
	}
	int ans=0;
	int l=0;
	for (int i=1; i<N; i++) {
		if (V[l]!=V[i]) {
			long long sz=i-l;
			ans+=(sz*sz+sz)/2LL;
			l=i;
		}
	}
	long long sz=N-l;
	ans+=(sz*sz+sz)/2LL;
	cout << ans << endl;

	// ans=0;
	// for (int i=0; i<N; i++) {
	// 	int sm=0;
	// 	for (int k=i; k<N; k++) {
	// 		sm+=V[k];
	// 		int sz=k-i+1;
	// 		if (sm%sz==0) ans++;
	// 	}
	// }
	// cout << ans << endl;
}