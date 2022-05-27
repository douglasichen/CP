#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<vector<int>> psa(N+1,vector<int>(N+1)), V(N+1,vector<int>(N+1));
	for (int i=0,y,x; i<M; i++) {
		cin>>y>>x;
		psa[y][x]=1;
		V[y][x]++;
	}
	for (int y=1; y<=N; y++) {
		for (int x=1; x<=N; x++) {
			psa[y][x]+=psa[y-1][x]+psa[y][x-1]-psa[y-1][x-1];
		}
	}
	vector<vector<int>> P;
	int mx=sqrt(M);
	for (int i=1; i<=mx; i++) {
		if (M%i==0) P.push_back({i,M/i}), P.push_back({M/i,i});
	}
	int best=0;
	for (vector<int> p : P) {
		int h=p[0], w=p[1];
		for (int y1=1; y1<=N-h+1; y1++) {
			for (int x1=1; x1<=N-w+1; x1++) {
				int y2=y1+h-1, x2=x1+w-1;
				int cnt=psa[y2][x2]-psa[y2][x1-1]-psa[y1-1][x2]+psa[y1-1][x1-1];
				if (cnt>best) best=cnt;
			}
		}
	}
	int ans=M-best;
	cout << ans << endl;

}