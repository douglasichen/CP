#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	vector<long long> T(N<<1);
	for (int i=0; i<N; i++) cin>>T[i+N];
	for (int i=0; i<Q; i++) {
		int op; cin>>op;
		if (op==1) {
			int L, R, v; cin>>L>>R>>v;
			for (L+=N-1, R+=N; L<R; L>>=1, R>>=1) {
				if (L&1) T[L]+=v, L++;
				if (R&1) T[R-1]+=v, R--;
			}
		}
		else {
			int p; cin>>p;
			long long ans=0;
			for (p+=N-1; p; p>>=1) ans+=T[p];
			cout << ans << endl;
		}
	}
}