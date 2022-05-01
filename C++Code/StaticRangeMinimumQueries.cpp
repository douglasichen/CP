#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	vector<int> LOGS(2e5+1);
	LOGS[1]=0;
	int f=1;
	for (int i=2; i<=2e5; i++) {
		if ((1<<(f+1))<=i) f++;
		LOGS[i]=f;
	}

	int N,Q; cin>>N>>Q;
	vector<int> V(N);
	vector<vector<int>> ST(N,vector<int>(LOGS[N]+1));
	for (int i=0; i<N; i++) {
		cin>>V[i];
		ST[i][0]=V[i];
	}

	
	for (int e=1; e<=LOGS[N]; e++) {
		int sz=1<<e, smSz=1<<(e-1), end=N-sz;
		for (int i=0; i<=end; i++) {
			ST[i][e]=min(ST[i][e-1],ST[i+smSz][e-1]);
		}
	}

	vector<int> ans(Q);
	for (int i=0; i<Q; i++) {
		int a,b; cin>>a>>b; a--; b--;
		int sz=b-a+1, e=LOGS[sz], eSz=1<<e;
		ans[i]=min(ST[a][e],ST[b-eSz+1][e]);
	}
	for (int i : ans) cout << i << endl;

}