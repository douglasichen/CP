#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> V;
vector<vector<bool>> isEmp;

void printV() {
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			cout << V[y][x] << ' ';
		}
		cout << endl;
	}
}

bool emp() {
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			if (V[y][x]!=0) return 0;
		}
	}
	return 1;
}

bool good() {
	for (int y=0; y<N; y++) {
		for (int x=1; x<M; x++) {
			if (V[y][x]<=V[y][x-1]) return 0;
		}
	}
	for (int x=0; x<M; x++) {
		for (int y=1; y<N; y++) {
			if (V[y][x]<=V[y-1][x]) return 0;
		}
	}
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			if (V[y][x]<=0) return 0;
		}
	}
	return 1;
}

void solve() {
	// equal element edge case
	// bounds
	// empty case;
	if (emp()) {
		for (int y=0; y<N; y++) V[y][0]=y+1;
		for (int y=0; y<N; y++) {
			for (int x=1; x<M; x++) {
				V[y][x]=V[y][x-1]+1;
			}
		}
	}

	// solve
	for (int y=0; y<N; y++) {
		for (int x=1; x<M; x++) {
			int prev=V[y][x-1];
			if (isEmp[y][x] && prev!=0) {
				if (V[y][x]<=prev) V[y][x]=prev+1;
			}
		}
		for (int x=M-2; x>=0; x--) {
			int prev=V[y][x+1];
			if (isEmp[y][x] && prev!=0) {
				if (V[y][x]>=prev || V[y][x]==0) V[y][x]=prev-1;
			}
		}
	}

	// cols
	for (int x=0; x<M; x++) {
		for (int y=1; y<N; y++) {
			int prev=V[y-1][x];
			if (isEmp[y][x] && prev!=0) {
				if (V[y][x]<=prev) V[y][x]=prev+1;
			}
		}
		for (int y=N-2; y>=0; y--) {
			int prev=V[y+1][x];
			if (isEmp[y][x] && prev!=0) {
				if (V[y][x]>=prev || V[y][x]==0) V[y][x]=prev-1;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M;
	V=vector<vector<int>>(N,vector<int>(M));
	isEmp=vector<vector<bool>>(N,vector<bool>(M));
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			cin>>V[y][x];
			if (V[y][x]==0) isEmp[y][x]=1;
		}
	}
	
	solve();
	if (good())
		printV();
	else cout << -1 << endl;
}