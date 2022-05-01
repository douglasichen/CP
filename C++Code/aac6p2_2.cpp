#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q,K=1; cin>>N>>Q;
	vector<int> dif(N+1),ends(N+1);
	for (int i=0; i<Q; i++) {
		int l,r; cin>>l>>r;	l--; r--;
		K=max(K,r-l+1);
		ends[r]++;

		dif[l]++;
		dif[r+1]--;
	}
	
	for (int i=1; i<=N; i++) {
		dif[i]+=dif[i-1];
	}
	
	vector<int> ans(N,1);
	for (int i=1; i<N; i++) {
		if (dif[i]==0) {
			ans[i]=ans[i-1];
		}
		else if (ends[i-1]==dif[i-1]) {
			ans[i]=ans[i-1];
		}
		else {
			ans[i]=ans[i-1]%K+1;
		}
	}
	cout << K << endl;
	for (int i=0; i<N; i++) {
		cout << ans[i] << (i==N-1 ? "\n" : " ");
	}
}