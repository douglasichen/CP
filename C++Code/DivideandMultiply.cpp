#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	vector<int> ans(T);
	for (int i=0; i<T; i++) {
		int N; cin>>N;
		vector<int> V(N);
		for (int o=0; o<N; o++) cin>>V[o];
		ans[i]=solve(N,V);
	}
	for (int i : ans) cout << i << endl;
}