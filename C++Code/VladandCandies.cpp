#include <bits/stdc++.h>
using namespace std;

bool solve(int N, vector<int> V) {
	if (N==1) {
		if (V[0]==1) return 1;
		return 0;
	}
	sort(V.begin(), V.end(), greater<int>());
	return !(V[0]-V[1]>1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	for (int i=0; i<T; i++) {
		int N; cin>>N;
		vector<int> V(N);
		for (int o=0; o<N; o++) cin>>V[o];
		cout << (solve(N,V) ? "YES" : "NO") << endl;
	}	
}