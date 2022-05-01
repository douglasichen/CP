#include <bits/stdc++.h>
using namespace std;

void solve() {

}

vector<vector<int>> dirs = {
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};

int R,C;

vector<int> add(vector<int> a, vector<int> b) {
	return {a[0]+b[0], a[1]+b[1]};
}

bool inBounds(vector<int> p) {
	return p[0]>=0 && p[0]<R && p[1]>=0 && p[1]<C;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>R>>C;
	bool V[R][C];
	for (int y=0; y<R; y++) {
		for (int x=0; x<C; x++) {
			char c; cin>>c;
			V[y][x]=(c=='X');
		}
	}
	bool K[R][C];
	for (int y=0; y<R; y++) {
		for (int x=0; x<C; x++) {
			if (V[y][x]) {
				int cnt=0;
				for (vector<int> dir : dirs) {
					vector<int> loc={y,x}, newLoc=add(loc,dir);
					if (inBounds(newLoc)) {
						if (!V[newLoc[0]][newLoc[1]]) cnt++;
					}
					else cnt++;
				}
				if (cnt<=2) K[y][x]=1;
				else K[y][x]=0;
			}
			else K[y][x]=0;
		}
	}
	
	vector<int> minB={INT_MAX,INT_MAX}, maxB={0,0};
	for (int y=0; y<R; y++) {
		for (int x=0; x<C; x++) {
			if (K[y][x]) {
				minB[0]=min(minB[0],y);
				minB[1]=min(minB[1],x);
				maxB[0]=max(maxB[0],y);
				maxB[1]=max(maxB[1],x);
			}
		}
	}

	for (int y=minB[0]; y<=maxB[0]; y++) {
		for (int x=minB[1]; x<=maxB[1]; x++) {
			// cout << y << ' ' << x <<
			cout << (K[y][x] ? 'X' : '.');
		}
		cout << endl;
	}
}