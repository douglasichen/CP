#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	long long N,M,K; cin>>N>>M>>K;
	vector<int> V(N);
	long long i=0;
	for (; i<M; i++) {
		int left=N-i-1;
		if (K-(i+1)-left<0) break;
		V[i]=i+1;
		K-=i+1;
	}
	long long bnd=0;
	for (; i<N; i++) {
		long long left=N-i-1, a=K-left, j=max(i-a,bnd), can=i-j;
		V[i]=V[j];
		bnd=j+1;
		K-=can;
	}
	if (K) cout << -1 << endl;
	else {
		for (int i : V) cout << i << ' '; cout << endl;
	}
}