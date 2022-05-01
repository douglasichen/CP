#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M,C; cin>>N>>M>>C;
	vector<int> nums(M);
	vector<long long> ans(N), dif(N+1);
	for (int i=0; i<N; i++) cin>>ans[i];
	for (int i=0; i<M; i++) cin>>nums[i];
	
	int mx=N-M+1;
	for (int l=0; l<M; l++) {
		int r=mx+l;
		dif[l]+=nums[l];
		dif[r]-=nums[l];
	}
	for (int i=1; i<N; i++) dif[i]+=dif[i-1];
	for (int i=0; i<N; i++) {
		ans[i]+=dif[i];
		ans[i]%=C;
	}

	for (int i : ans) cout << i << ' ';
	cout << endl;
}