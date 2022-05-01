// C++
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,Q; cin>>N>>Q;
	vector<int> V(N+1),psa(N+1);
	for (int i=1; i<=N; i++) cin>>V[i];
	psa[1]=V[1];
	for (int i=2; i<=N; i++) psa[i]=psa[i-1]+V[i];
	for (int i=0; i<Q; i++) {
		int L,R; cin>>L>>R;
		int ans=psa[R]-psa[L-1];
		cout << ans << endl;
	}
}