#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> A(N),B(N);
	for (int i=0; i<N; i++) cin>>A[i];
	for (int i=0; i<N; i++) cin>>B[i];

	vector<vector<int>> R;
	for (int i=0; i<N; i++) {
		if (!B[i]) {
			int b=i;
			while (b+1<N && !B[b+1]) b++;
			R.push_back({b,b-i+1});
			i=b;
		}
	}
	
	vector<int> C;
	for (int i=0; i<N; i++) if (!A[i]) C.push_back(i);
	int at=0;
	for (vector<int> v : R) {
		vector<int> b=v[0], c0=v[1];
		ans.push_back({C[at],C[at+c0]});
		at+=c0;
	}
	
}