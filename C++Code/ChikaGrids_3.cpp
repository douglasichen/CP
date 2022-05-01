#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<vector<int>> V(N+1,vector<int>(M+1));
	for (int y=1; y<=N; y++) {
		for (int x=1; x<=M; x++) {
			cin>>V[y][x];
		}
	}
	
	if (V[1][1]==0) V[1][1]=1;
	for (int y=1; y<=N; y++) {
		for (int x=1; x<=M; x++) {
			if (V[y][x]==0) {
				V[y][x]=max(V[y-1][x],V[y][x-1])+1;
			}
		}
	}

	bool gd=1;
	for (int y=1; y<=N; y++) {
		for (int x=2; x<=M; x++) {
			if (V[y][x]<=V[y][x-1]) {
				gd=0;
				break;
			}
		}
	}
	for (int x=1; x<=M; x++) {
		for (int y=2; y<=N; y++) {
			if (V[y][x]<=V[y-1][x]) {
				gd=0;
				break;
			}
		}
	}

	if (gd) {
		for (int y=1; y<=N; y++) {
			for (int x=1; x<=M; x++) {
				cout << V[y][x] << ' ';
			}
			cout << endl;
		}
	}
	else cout << -1 << endl;
}