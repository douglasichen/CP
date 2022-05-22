#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<vector<int>> V(N,vector<int>(2));
	for (int i=0; i<N; i++) cin>>V[i][0]>>V[i][1];

	long long mx=0;
	for (int i=0; i<N-1; i++) {
		for (int o=i+1; o<N; o++) {
			long long x=abs(V[i][0]-V[o][0]), y=abs(V[i][1]-V[o][1]);
			// cout << x << ' ' << y << endl;
			cout << x*y << endl;
			// mx=max(mx,c);
		}
	}
	cout << mx << endl;
}