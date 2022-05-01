#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	long long N,K; cin>>N>>K;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	
	long long loss=0;
	int dif=0;
	vector<int> fnd(N+1);
	int left=0;
	for (int i=0; i<N; i++) {
		if (!fnd[V[i]]) dif++;
		fnd[V[i]]++;

		while (dif==K && left<=i) {
			fnd[V[left]]--;
			if (fnd[V[left]]==0) dif--;
			left++;
		}
		if (dif==K) continue;
		int len=i-left+1;
		loss+=len;
	}
	long long ans=(N*N+N)/2-loss;
	cout << ans << endl;
}