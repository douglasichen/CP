#include <bits/stdc++.h>
using namespace std;

const int MAX_N=100, MAX_LOG=32;
int V[MAX_N];
int M[MAX_N][MAX_LOG];	// max exp: 2^31 

int solve(int l, int r) {
	// min of l -> r inclusive
	int len=r-l+1;
	
	int bigE=log(len), eSize=(1<<bigE);
	return min(M[l][bigE], M[r-eSize+1][bigE]);
}

int main() {
	// taking input
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		cin>>V[i];
		M[i][0]=V[i];
	}

	// precompute min value ranges of size powers of 2
	for (int e=1; e<=MAX_LOG-1; e++) {
		int size=(1<<e);
		for (int i=0; i<=n-size; i++) {
			// min of large chunk is decided upon min of 2 small chunks within big chunk
			int prevE=e-1, i2=i+(size>>1);
			M[i][e]=min(M[i][prevE], M[i2][prevE]);
			// cout << "i: " << i << " " << "i2: " << i2 << endl;
			// cout << "From " << i << " to " << i+size-1 << endl;
		}
	}

	// answering queries
	int q; cin>>q;
	int ans[q];
	for (int i=0; i<q; i++) {
		int l,r; cin>>l>>r;
		ans[i]=solve(l,r);
	}
	for (int i : ans) cout << i << endl;
}