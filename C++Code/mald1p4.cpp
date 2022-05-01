#include <bits/stdc++.h>
using namespace std;



int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	// input
	int N,F; cin>>N>>F;
	vector<int> H(N+1),lim(N+1,INT_MAX);
	for (int i=1; i<=N; i++) cin>>H[i];
	for (int i=0; i<F; i++) {
		int a,b; cin>>a>>b;
		lim[a]=min(lim[a],H[a]-b);
	}
	// for (int i=1; i<=N; i++) cout << lim[i] << " ";
	// cout << endl;

	// ST
	vector<int> LOGS(1e6+1);
	int p=1;
	for (int i=2; i<=1e6; i++) {
		if (1<<(p+1)<=i) p++;
		LOGS[i]=p;
	}

	int MX_E=LOGS[N];
	vector<vector<int>> ST(N+1,vector<int>(MX_E+1));
	for (int i=1; i<=N; i++) ST[i][0]=lim[i];
	for (int e1=1; e1<=MX_E; e1++) {
		int e2=e1-1, sz=1<<e1, hSz=1<<e2, bnd=N-sz+1;
		for (int i=1; i<=bnd; i++) {
			ST[i][e1]=min(ST[i][e2],ST[i+hSz][e2]);
		}
	}
	
	
	long long ans=0;
	for (int a=1; a<=N; a++) {
		for (int b=a; b<=N; b++) {
			int sz=b-a+1;
			int e=LOGS[sz];
			long long rep=min(ST[a][e],ST[b-(1<<e)+1][e]);
			if (rep!=INT_MAX) {
				ans=max(ans,rep*sz);
			}
		}
	}
	cout << ans << endl;
	
}