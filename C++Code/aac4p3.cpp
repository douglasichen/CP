#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<vector<long long>> S(M,vector<long long>(2)),P(N,vector<long long>(2));
	vector<bool> skip(M);
	for (int i=0; i<N; i++) cin>>P[i][0]>>P[i][1];
	for (int i=0; i<M; i++) cin>>S[i][0]>>S[i][1];
	for (int i=0; i<M-1; i++) {
		for (int o=i+1; o<M; o++) {
			vector<long long> a=S[i],b=S[o];
			if (a[0]*b[1]==a[1]*b[0]) {
				skip[i]=1;
				break;
			}
		}
	}
	vector<map<long long,long long>> F(M);
	for (int i=0; i<M; i++) {
		if (skip[i]) continue;
		long long K=S[i][0],D=S[i][1];
		for (int o=0; o<N; o++) {
			long long X=P[o][0],Y=P[o][1];
			F[i][K*X-D*Y]++;
		}
	}
	long long ans=0;
	for (int i=0; i<M; i++) {
		for (auto o=F[i].begin(); o!=F[i].end(); o++) {
			long long val=(*o).second;
			ans+=val*(val-1LL)/2LL;
		}
	}
	cout << ans << '\n';
}