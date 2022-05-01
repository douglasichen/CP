#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N; cin>>N;
	vector<bool> h(N+1);
	for (int i=0; i<N-1; i++) {
		int inp; cin>>inp;
		h[inp]=1;
	}
	for (int i=1; i<=N; i++) {
		if (!h[i]) {
			cout << i << endl;
			break;
		}
	}
}