#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	vector<long long> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	
	if (K>=N) {
		if (K>N) cout << 0 << endl;
		else {
			long long sm=0;
			for (int i : V) sm+=i;
			cout << max(0LL,sm) << endl;
		}
		return 0;
	}

	vector<vector<long long>> groups(K);
	long long sm=0;
	for (int i=0; i<K; i++) sm+=V[i];
	groups[0].push_back(sm);

	for (int r=K; r<N; r++) {
		int l=r-K;
		sm-=V[l];
		sm+=V[r];
		groups[(l+1)%K].push_back(sm);
	}

	long long ans=0;
	for (vector<long long> g : groups) {
		long long best=0, gs=0;
		int sz=g.size();
		for (int i=0; i<sz; i++) {
			gs=max(g[i],gs+g[i]);
			best=max(best,gs);
		}
		ans=max(ans,best);
	}
	cout << ans << endl;
}