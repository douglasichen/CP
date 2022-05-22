#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>M>>N;
	vector<int> V(N),L(M+2),R(M+2);
	for (int i=0; i<N; i++) cin>>V[i];
	int hf=N/2;
	for (int i=0; i<hf; i++) L[V[i]]++;
	for (int i=hf; i<2*hf; i++) R[V[i]]++;
	int l=hf-1,ans=0;
	for (int K=hf; K>0; K--) {
		bool gd=1;
		vector<int> D(M+2);
		for (int i=M; i>=1; i--) {
			D[i]=D[i+1]+R[i+1]-L[i];
			if (D[i]<0) {
				gd=0;
				break;
			}
		}
		if (gd) {
			ans=K;
			break;
		}
		// for (int i=1; i<=M; i++) cout << L[i] << ' ' << R[i] << endl;
		// cout << endl;
		L[V[l]]--;
		R[V[l]]++;
		R[V[l+K]]--;
		R[V[l+K-1]]--;
		l--;
	}
	cout << ans << endl;
}