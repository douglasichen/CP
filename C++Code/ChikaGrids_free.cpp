#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N,M;
vector<vector<ll>> V;
vector<vector<bool>> emp;

void printV(vector<vector<ll>> v) {
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			cout << v[y][x] << " ";
		}
		cout << endl;
	}
}

void printV(vector<vector<bool>> v) {
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			cout << v[y][x] << " ";
		}
		cout << endl;
	}
}

void brush() {
	for (int i=0; i<N; i++) V[i][0]=i+1;
	for (int y=0; y<N; y++) {
		for (int x=1; x<M; x++) {
			long long behind=V[y][x-1];
			V[y][x]=behind+1LL;
		}
	}
}
void rush() {
	for (int y=0; y<N; y++) {
		for (int x=1; x<M; x++) {
			ll behind=V[y][x-1];
			if (behind!=0 && emp[y][x]) {
				if (V[y][x]<=behind || V[y][x]==0) {
					V[y][x]=behind+1LL;
				}
			}
		}
		for (int x=M-2; x>=0; x--) {
			ll behind=V[y][x+1];
			if (behind!=0 && emp[y][x]) {
				if (V[y][x]>=behind || V[y][x]==0) {
					V[y][x]=behind-1LL;
				}
			}
		}
	}
	for (int x=0; x<M; x++) {
		for (int y=1; y<N; y++) {
			ll behind=V[y-1][x];
			if (behind!=0 && emp[y][x]) {
				if (V[y][x]<=behind || V[y][x]==0) {
					V[y][x]=behind+1LL;
				}
			}
		}
		for (int y=N-2; y>=0; y--) {
			ll behind=V[y+1][x];
			if (behind!=0 && emp[y][x]) {
				if (V[y][x]>=behind || V[y][x]==0) {
					V[y][x]=behind-1LL;
				}
			}
		}
	}
	// printV(V);
}

void pom() {
	bool has=0;
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			if (!emp[y][x]) {
				has=1;
				break;
			}
		}
	}
	if (has) {
		rush();
	}
	else {
		brush();
	}
}

bool good() {
	for (int y=0; y<N; y++) {
		for (int x=1; x<M; x++) {
			ll behind=V[y][x-1];
			if (behind>=V[y][x]) return 0;
		}
	}
	for (int x=0; x<M; x++) {
		for (int y=1; y<N; y++) {
			ll behind=V[y-1][x];
			if (behind>=V[y][x]) return 0;
		}
	}
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			if (V[y][x]<=0 || V[y][x]>1e18) return 0;
		} 
	}
	
	return 1;
}

void solve() {
	pom();
	if (good()) {
		printV(V);
	}
	else {
		cout << -1 << endl;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M;
	V=vector<vector<ll>>(N,vector<ll>(M));
	emp=vector<vector<bool>>(N,vector<bool>(M));
	
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			cin>>V[y][x];
			if (V[y][x]==0) emp[y][x]=1;
		}
	}
	solve();
}