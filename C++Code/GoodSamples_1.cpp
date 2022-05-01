#include <bits/stdc++.h>
using namespace std;

int N,M;
long long K;

vector<int> solve() {
	if (K<N) return {-1};
	vector<int> V(N);
	if (K==N) {
		for (int i=0; i<N; i++) V[i]=1;
		return V;
	}
	
	int j=0;
	while (j<N) {
		int start=j;
		for (int i=0; i<M && j<N; i++) {
			V[start+i]=i+1;
			j++;
		}
	}
	
	int R=N/M * M, E=N-R;
	int dif=R-M;
	long long have=(R*R+R)/2 - (dif*dif+dif)/2 + M*E;
	if (K>have) return {-1};

	

	return V;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M>>K;
	vector<int> ans=solve();
	for (int i : ans) cout << i << ' ';
	cout << endl;
}