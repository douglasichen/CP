#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];	
	int best=0,sm=0;
	for (int i=0; i<N; i++) {
		sm=max(sm+V[i],V[i]);
		best=max(best,sm);
	}
	cout << best << endl;
}