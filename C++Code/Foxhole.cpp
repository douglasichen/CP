#include <bits/stdc++.h>
using namespace std;

vector<int> c2dir(char c) {
	if (c=='L') return {0,-1};
	if (c=='R') return {0,1};
	if (c=='D') return {1,0};
	return {0,0};
}

vector<int> add(vector<int> a, vector<int> b) {
	return {a[0]+b[0], a[1]+b[1]};
}

char val(vector<vector<char>> g, vector<int> pos) {
	return g[pos[0]][pos[1]];
}

bool inBounds(int h, int w, vector<int> pos) {
	return pos[0]>=0 && pos[0]<=h-1 && pos[1]>=0 && pos[1]<=w-1;
}

int solve(int h, int w, int n, vector<vector<char>> g, vector<char> instr) {

	// for (int y=0; y<h; y++) {
	// 	for (int x=0; x<w; x++) {
	// 		cout << g[y][x] << ' ';
	// 	}
	// 	cout << endl;
	// }

	int ans=0;
	vector<int> pos={0,0};
	for (char c : instr) {
		vector<int> dir=c2dir(c);
		vector<int> nPos=add(pos,dir);
		if (!inBounds(h,w,nPos) || val(g,nPos)=='S') continue;

		// cout << "nPos: " << nPos[0] << " " << nPos[1] << endl; 

		// treasure and change to empty cell
		if (val(g,nPos)=='T') {
			ans++;
		}
		g[nPos[0]][nPos[1]]='E';

		// pull down
		vector<int> down={1,0}, up={-1,0};
		vector<int> below=add(nPos,down);
		// cout << "below: " << below[0] << " " << below[1] << endl;
		while (inBounds(h,w,below) && val(g,below)=='E') {
			if (val(g,below)=='T') {
				ans++;
				g[below[0]][below[1]]='E';
			}
			below=add(below,down);
		}
		nPos=add(below,up);

		

		pos=nPos;

	}
	return ans;
}

int main() {
	int t; cin>>t;
	vector<int> ans(t);
	for (int i=0; i<t; i++) {
		int h,w,n; cin>>h>>w>>n;
		vector<vector<char>> g(h+1,*(new vector<char>(w)));
		g[0]=*(new vector<char>(w,'E'));
		for (int y=1; y<h+1; y++) {
			for (int x=0; x<w; x++) {
				cin>>g[y][x];
			}
		}
		vector<char> instr(n);
		for (int k=0; k<n; k++) {
			cin>>instr[k];
		}
		ans[i]=solve(h+1,w,n,g,instr);
	}

	for (int i : ans) cout << i << endl;
}