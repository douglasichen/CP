#include <bits/stdc++.h>
using namespace std;

int N,K,Q;
vector<int> dif(200002),psa(200001);

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>K>>Q;
	for (int i=0; i<N; i++) {
		int l,r; cin>>l>>r;
		dif[l]++;
		dif[r+1]--;
	}
	// fully compute dif
	for (int i=1; i<200002; i++) {
		dif[i]+=dif[i-1];
	}

	int cnt=0;
	for (int i=0; i<200001; i++) {
		cnt+=(dif[i]>=K);
		psa[i]=cnt;
	}
	vector<int> ans(Q);
	for (int i=0; i<Q; i++) {
		int l,r; cin>>l>>r;
		ans[i]=psa[r]-psa[l-1];
	}
	for (int i : ans) cout << i << endl;
}