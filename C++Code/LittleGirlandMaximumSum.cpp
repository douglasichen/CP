#include <bits/stdc++.h>
using namespace std;

int N,Q;
vector<int> V,F;
vector<vector<int>> dif;

bool sorter(vector<int> a, vector<int> b) {
	return a[0]>b[0];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>Q;
	V=vector<int>(N);
	// QS=vector<vector<int>>(Q);
	F=V;
	dif=vector<vector<int>>(N+1,vector<int>(2)); // val, ind
	for (int i=0; i<N; i++) cin>>V[i];
	sort(V.begin(),V.end(),greater<int>());
	
	for (int i=0; i<Q; i++) {
		int l,r; cin>>l>>r; l--; r--;
		dif[l][0]++;
		dif[r+1][0]--;
		// QS[i]={l,r};
	}
	for (int i=1; i<N; i++) {
		dif[i][0]+=dif[i-1][0];
		dif[i][1]=i;
	}

	vector<vector<int>> ex=dif;
	sort(ex.begin(),ex.end(),sorter);
	for (int i=0; i<N; i++) {
		F[ex[i][1]]=V[i];
	}

	unsigned long long sm=0;
	for (int i=0; i<N; i++) {
		sm+=(unsigned long long)F[i] * (unsigned long long)dif[i][0];
	}
	cout << sm << endl;
	
	// F list is ready for counting
	// vector<unsigned long long> psa(N);
	// unsigned long long cnt=0;
	// for (int i=0; i<N; i++) {
	// 	cnt+=F[i];
	// 	psa[i]=cnt;
	// }

	// unsigned long long sm=0;
	// for (int i=0; i<Q; i++) {
	// 	int l=QS[i][0], r=QS[i][1];
	// 	unsigned long long take=(l==0 ? 0LL : psa[l-1]);
	// 	sm+=psa[r]-take;
	// }
	// cout << sm << endl;
}