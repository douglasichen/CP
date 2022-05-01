#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	vector<int> V(N);
	vector<int> diff(N+1);
	for (int i=0; i<N; i++) cin>>V[i];
	for (int i=0; i<Q; i++) {
		int l,r,x; cin>>l>>r>>x;
		diff[l]+=x; diff[r+1]-=x;
	}
	for (int i=1; i<N; i++) {
		diff[i]+=diff[i-1];
	}
	for (int i=0; i<N; i++) {
		V[i]+=diff[i];
	}
	for (int i : V) cout << i << ' ';
}