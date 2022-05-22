#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	vector<vector<int>> V(N+2,vector<int>(2));
	for (int i=0; i<=N+1; i++) V[i]={i-1,i+1};
	// V[0][0]=0;
	// V[N+1][1]=N+1;

	for (int i=0,A,B,X; i<Q; i++) {
		cin>>A>>B>>X;
		if (V[X][1]==A) continue;
		
		vector<int> pA=V[A], pB=V[B], pX=V[X];
		V[X][1]=A;
		V[A][0]=X;
		
		V[pX[1]][0]=B;
		V[B][1]=pX[1];

		V[pA[0]][1]=pB[1];
		V[pB[1]][0]=pA[0];
	}
	int at=V[0][1];
	vector<int> ans;
	while (ans.size()<N) {
		ans.push_back(at);
		at=V[at][1];
	}
	for (int i : ans) cout << i << ' '; cout << endl;
}