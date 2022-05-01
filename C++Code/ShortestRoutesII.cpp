#include <bits/stdc++.h>
using namespace std;

int N,M,Q;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M>>Q;
	vector<vector<long long>> D(N+1,vector<long long>(N+1,1e18));
	for (int i=1; i<=N; i++) D[i][i]=0;
	for (int i=0; i<M; i++) {
		int a,b;
		long long c;
		cin>>a>>b>>c;
		D[a][b]=min(D[a][b],c);
		D[b][a]=min(D[b][a],c);
	}
	for (int i=1; i<=N; i++) {
		for (int y=1; y<=N; y++) {
			for (int x=1; x<=N; x++) {
				D[y][x]=min(D[y][x],D[y][i]+D[i][x]);
			}
		}
	}

	long long ans[Q];
	for (int i=0; i<Q; i++) {
		int a,b; cin>>a>>b;
		ans[i]=D[a][b];
	}
	for (long long i : ans) {
		if (i==1e18) cout << -1 << endl;
		else cout << i << endl;
	}
}