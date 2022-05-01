#include <bits/stdc++.h>
using namespace std;

int N,Q;
vector<int> V,dif;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>Q;
	V=vector<int>(N);
	dif=vector<int>(N+1);
	for (int i=0; i<N; i++) cin>>V[i];
	sort(V.begin(),V.end(),greater<int>());
	
	for (int i=0; i<Q; i++) {
		int l,r; cin>>l>>r; l--; r--;
		dif[l]++;
		dif[r+1]--;
	}
	for (int i=1; i<N; i++) {
		dif[i]+=dif[i-1];
	}

	sort(dif.begin(), dif.end(), greater<int>());

	unsigned long long sm=0;
	for (int i=0; i<N; i++) {
		sm+=(unsigned long long)V[i] * (unsigned long long)dif[i];
	}
	cout << sm << endl;
}