#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	unsigned long long N, K; cin>>N>>K;
	vector<int> V(N);
	long long oK=K;

	if (N==1) cout << K << endl;
	else {
		unsigned long long sm=0;
		for (int i=1; i<=N-1; i++) {
			V[i-1]=i;
			sm+=i;
		}
		unsigned long long m=ceil((float)(N+sm)/(float)K);
		while (K*m<N+sm) m++;
		K*=m;

		int nxt=K-sm;
		V[N-1]=nxt;

		for (int i=0; i<N; i++) {
			cout << V[i];
			if (i<N-1) cout << ' ';
		}
		cout << endl;

	// 	cout << "nxt: " << nxt << endl;
	// 	cout << "Km=" << K << endl;
	// 	sm+=nxt;
	// 	cout << "sm=" << sm << endl;
	}
}