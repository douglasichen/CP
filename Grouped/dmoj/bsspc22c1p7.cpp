#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans=INT_MIN;
	int N,M; cin>>N>>M;
	vector<vector<int>> V(N, vector<int>(3)), D;
	for (int i=0; i<N; i++) cin>>V[i][0]>>V[i][1], V[i][2]=i;
	D=V;
	sort(V.begin(), V.end());
	sort(V.begin(), V.end(), [](vector<int> a, vector<int> b){
		return a[1]<b[1];
	});

	// sum of used D
	vector<int> T(N<<1);
	for (int i=N; i<N*2; i++) T[i]=1;
	for (int i=N-1; i; i--) T[i]=T[i<<1]+T[i<<1|1];

	int d=M;
	for (int i=0; i<N; i++) {
		if (d>N) break;
		int at=lower_bound(D.begin(), D.end(), V[i])-D.begin();

		// lower `at` in tree
		T[at+=N]=0;
		for (at>>=1; at; at>>=1) T[at]=T[at<<1]+T[at<<1|1];

		//remake sum
		int sm=0;
		int L=0, R=d;
		for (L+=N, R+=N; L<R; L>>=1, R>>=1) {
			if (L&1) sm+=T[L++];
			if (R&1) sm+=T[--R];
		}
	
		// while sm<M, move d pointer
		while (d<N && sm<M) {
			d++;
			// remake sum.
			int L=0, R=d;
			sm=0;
			for (L+=N, R+=N; L<R; L>>=1, R>>=1) {
				if (L&1) sm+=T[L++];
				if (R&1) sm+=T[--R];
			}
		}
		if (sm==M) ans=max(ans,V[i][0]-D[d-1][1]);
	}
	cout << ans << endl;

}