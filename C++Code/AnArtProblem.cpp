#include <bits/stdc++.h>
using namespace std;

int N,M,K;
vector<vector<int>> canvas;
vector<vector<bool>> hasCol;
vector<vector<int>> empLocs;

// bool sorter(vector<int> a, vector<int> b) {
// 	if (a[0]==b[0]) {
// 		return a[1]<b[1];
// 	}
// 	return a[0]<b[0];
// }

vector<int> sub(vector<int> a, vector<int> b) {
	return {a[0]-b[0], a[1]-b[1]};
}

vector<vector<int>> dirs = {
	{1,0},
	{0,1},
	{-1,0},
	{0,-1},
};

vector<int> mult(vector<int> a, int b) {
	return {a[0]*b, a[1]*b};
}

vector<int> add(vector<int> a, vector<int> b) {
	return {a[0]+b[0], a[1]+b[1]};
}

int getCol(vector<int> loc) {
	int best=INT_MAX;
	for (int i=1; i<=K; i++) {
		ou
		for (vector<int> dir : dirs) {
			vector<int> pos=add(loc,mult(dir,i));
			// cout << "h: " << pos[0] << ' ' << pos[1] << endl;
			// if in bounds
			if (pos[0]>=0 && pos[0]<=N-1 && pos[1]>=0 && pos[1]<=M-1) {
				if (hasCol[pos[0]][pos[1]]) {
					found=1;
					best=min(best,canvas[pos[0]][pos[1]]);
				}
			}
		}
		// cout << endl;
		if (found) {
			return best;
		}
	}
	return 0;
}



int main() {
	cin>>N>>M>>K;
	canvas=*(new vector<vector<int>>(N, *(new vector<int>(M))));
	hasCol=*(new vector<vector<bool>>(N, *(new vector<bool>(M))));
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			cin>>canvas[y][x];
			// if !=0 or ==0
			if (canvas[y][x]!=0) {
				hasCol[y][x]=1;
			}
			else {
				empLocs.push_back({y,x});
			}
		}
	}


	vector<vector<int>> newCanv(N,*(new vector<int>(M)));
	for (vector<int> emp : empLocs) {
		newCanv[emp[0]][emp[1]]=getCol(emp);
	}

	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			if (hasCol[y][x])
				cout << canvas[y][x] << " ";
			else
				cout << newCanv[y][x] << " ";
		}
		cout << endl;
	}
}