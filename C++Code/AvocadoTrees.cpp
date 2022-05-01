#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q,H; cin>>N>>Q>>H;
	vector<int> T(N+1);
	for (int i=1; i<=N; i++) {
		int h,v; cin>>h>>v;
		if (h<=H) T[i]=v;
	}
	vector<int> psa(N+1);
	psa[1]=T[1];
	for (int i=2; i<=N; i++) {
		psa[i]=psa[i-1]+T[i];
	}

	int ans=0;
	for (int i=0; i<Q; i++) {
		int l,r; cin>>l>>r;
		ans=max(ans,psa[r]-psa[l-1]);
	}
	cout << ans << endl;
	
}