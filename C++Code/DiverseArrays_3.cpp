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

	int loss=0;
	if (K>1) {
		for (int i=0; i<N; i++) {
			vector<bool> fnd(N+1);
			int difs=0;
			int j=i;
			while (j>=0 && difs<K) {
				if (!fnd[V[j]]) {
					difs++;
					fnd[V[j]]=1;	
				}
				if (difs==K) j++;
				else j--;
			}
			if (j<0) j++;
			cout << i << " to " << j << endl;
			int len=i-j+1;
			loss+=(len*len+len)/2;
		}
	}
	int ans=(N*N+N)/2-loss;
	cout << ans << endl;
}