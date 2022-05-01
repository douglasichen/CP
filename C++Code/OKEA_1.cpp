#include <bits/stdc++.h>
using namespace std;

void solve(int N, int M) {
	if (N%2==0) {
		vector<vector<int>> V(N,vector<int>(M));
		int num=1;
		for (int y=0; y<N; y+=2) {
			for (int x=0; x<M; x++) {
				V[y][x]=num;
				num+=2;
			}
		}
		num=2;
		for (int y=1; y<N; y+=2) {
			for (int x=0; x<M; x++) {
				V[y][x]=num;
				num+=2;
			}
		}

		cout << "YES" << endl;
		for (int y=0; y<N; y++) {
			for (int x=0; x<M; x++) {
				cout << V[y][x] << ' ';
			}
			cout << endl;
		}
	}
	else {
		if (M==1) {
			cout << "YES" << endl;
			for (int i=1; i<=N; i++) cout << i << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	for (int i=0; i<T; i++) {
		int N,M; cin>>N>>M;
		solve(N,M);
	}
}