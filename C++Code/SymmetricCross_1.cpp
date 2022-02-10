#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;

bool work(int y, int x, int k) {
	for (int i=k; i>0; i--) {
		int a=g[y-i][x];
		int b=g[y+i][x];
		int c=g[y][x-i];
		int d=g[y][x+i];
		if (a!=b || a!=c || a!=d) return 0;
	}
	return 1;
}

int main() {
	cin>>n>>m;
	g=*(new vector<vector<int>>(n, *(new vector<int>(m))));
	
	for (int y=0; y<n; y++)
		for (int x=0; x<m; x++)
			cin>>g[y][x];

	int maxK=min(n,m)/2;
	for (int k=maxK; k>=0; k--) {
		for (int y=k; y<n-k; y++) {
			for (int x=k; x<m-k; x++) {
				if (work(y,x,k)) {
					cout << k << ' ' << y+1 << ' ' << x+1 << endl; 
					return 0;
				}
			}
		}
	}
}