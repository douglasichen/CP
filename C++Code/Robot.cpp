#include <bits/stdc++.h>
using namespace std;

int N,M;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	vector<vector<int>> P(N,vector<int>(2));
	int dis=0;
	for (int i=0; i<N; i++) {
		cin>>P[i][0]>>P[i][1];
		dis+=abs(P[i][0]);
		dis+=abs(P[i][1]);
	}

	for (int i=0; i<M; i++) {
		char c; cin>>c;
		vector<int> displace;
		if (c=='S') {
			// up
			displace
		}
		else if (c=='J') {
			// down
		}
		else if (c=='I') {
			// right
		}
		else {
			// left
		}
	}

}