#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int N,K; cin>>N>>K;
	char V[N];
	for (int i=0; i<N; i++) cin>>V[i];

	vector<char> ans(N-K);
	int p=0;

	// best starting pos
	vector<int> best={0,V[0]};
	while (K>0) {
		bool found=false;
		int bound=best[0]+K;
		// cout << "Look from: " << best[0] << " to " << bound << endl;
		for (int i=best[0]; i<=bound && i<N; i++) {
			if (V[i]<=best[1]) {
				best={i,V[i]};
				found=true;
			}
		}
		K-=best[0];
		
		// cout << "best: " << best[0] << endl;

		// apply
		ans[p]=best[1];
		p++;

		// change
		best={best[0]+1,V[best[0]+1]};

		

		// break;
		
	}
	
	
	for (int i=best[0]; i<N; i++) {
		ans[p]=V[i];
		p++;
	}

	bool found=0;
	for (char c : ans) {
		
		// if (!found) {
		// 	found=(c!='0');

		// }
		cout << c;
	}
	cout << endl;
}