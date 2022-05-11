#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	unsigned long long ans=0;
	int N; cin>>N;
	vector<int> V(N);
	vector<int> O(20); // location in bin num -> which num
	for (int i=0,inp; i<N; i++) {
		cin>>inp;
		V[i]=inp;
		int e=0;
		while (inp) {
			O[e]+=inp&1;
			inp>>=1;
			e++;
		}
	}
	// for (int y=0; y<20; y++) {
	// 	for (int x=0; x<N; x++) cout << psa[y][x] << ' ';
	// 	cout << endl;
	// }
	unsigned long long ones,zeros;
	for (int i=0; i<N-1; i++) {
		for (int e=0; e<20; e++) {
			O[e]-=V[i]&1;
			ones=O[e], zeros=N-1-i-ones;
			// cout << i << ' ' << e << ": " << ones << ' ' << zeros << endl;
			if (V[i]&1) ans+=(1<<e)*zeros;
			else ans+=(1<<e)*ones;
			
			V[i]>>=1;
		}
	}
	cout << ans << endl;
}