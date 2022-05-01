#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	unsigned long long ANS=0;
	int N; cin>>N;
	vector<int> V(N);
	for (int i=0; i<N; i++) {
		cin>>V[i];
	}
	for (int i=0; i<N-1; i++) {
		int sm=0;
		for (int k=i+1; k<N; k++) {
			ANS+=(V[i]^V[k]);
			sm+=(V[i]^V[k]);
			cout << V[i] << " vs " << V[k] << " = " << (V[i]^V[k]) << endl;
		}
		cout << "s: " << sm << endl;
	}
	cout << ANS << endl;
}