#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	sort(V.begin(),V.end());
	int bnd=N-1,y=0,t=0;
	for (int i=0; i<bnd; i++) {
		y++;
		int dt=V[i]-t;
		t=V[i];
		if (y>=K) {
			int cut=min(y/K,bnd-i);
		}
	}
}