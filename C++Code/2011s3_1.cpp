#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_map<int,bool>> good;
unordered_map<int, unordered_map<int,bool>> tryG;

bool in(int x, int y) {
	vector<int> dis2Corn = {x%5, y%5};
	return good[dis2Corn[0]][dis2Corn[1]];
}


bool solve(int m, int x, int y) {
	
	for (int i=m-1; i>=0; i--) {
		int scaleBack=pow(5,i);
		int zoomX=x/scaleBack;
		int zoomY=y/scaleBack;
		if (in(zoomX, zoomY)) {
			return 1;
		}
		else {
			if (!tryG[zoomX][zoomY]) return 0;
		}
	}
	return 0;
}

int main() {
	good[1][0]=1;
	good[2][0]=1;
	good[3][0]=1;
	good[2][1]=1;
	
	tryG[1][1]=1;
	tryG[2][2]=1;
	tryG[3][1]=1;

	tryG[1][0]=1;
	tryG[2][0]=1;
	tryG[3][0]=1;
	tryG[2][1]=1;

	int t; cin>>t;
	bool ans[t];
	for (int i=0; i<t; i++) {
		int m,x,y; cin>>m>>x>>y;
		ans[i]=solve(m,x,y);
	}	
	for (bool i : ans) cout << (i ? "crystal" : "empty") << endl;
}