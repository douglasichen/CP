#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

bool in (int a, int b, int N, int M) {
	return a>=0 && a<N && b>=0 && b<M;
}

long long solve(int N, int M, vector<vector<int>> &V) {
	long long ans=0;
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			long long sm=0;
			for (int i=-(N-1); i<=N-1; i++) {
				if (in(y+i,x+i,N,M)) sm+=V[y+i][x+i];
				if (i && in(y+i,x-i,N,M)) sm+=V[y+i][x-i];
			}
			ans=max(ans,sm);
		}
	}
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	for (int i=0; i<T; i++) {
		int N,M; cin>>N>>M;
		vector<vector<int>> V(N,vector<int>(M));
		for (int y=0; y<N; y++)
			for (int x=0; x<M; x++)
				cin>>V[y][x];
		cout << solve(N,M,V) << endl;
	}	
}