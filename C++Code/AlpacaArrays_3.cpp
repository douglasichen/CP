#include <bits/stdc++.h>
using namespace std;

int N,Q;
vector<int> V;

bool solve(int l, int r, int x) {
	l--; r--;
	bool ans=0;

	vector<bool> needed(1e6+1);
	for (int i=l; i<=r; i++) {
		int e=V[i];
		if (needed[e]) ans=1;
		if (x%e==0) {
			int need=x/e;
			if (need!=e) {
				needed[need]=1;
			}
		}
	}

	return ans;
}

int main() {
	cin>>N>>Q;
	V=*(new vector<int>(N));
	for (int i=0; i<N; i++) {
		cin>>V[i];
	}
	

	// queries
	vector<bool> ans(Q);
	for (int i=0; i<Q; i++) {
		int l,r,x; cin>>l>>r>>x;
		ans[i]=solve(l,r,x);
	}
	for (bool a : ans) cout << (a ? "YES" : "NO") << endl;
}