#include <bits/stdc++.h>
using namespace std;

char val(pair<int,int> pos, vector<vector<char>> grid) {
	return grid[pos.first][pos.second];
}

vector<pair<int,int>> allDir = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0},
};
vector<pair<int,int>> upDown = {
	{1,0},
	{-1,0},
};
vector<pair<int,int>> leftRight = {
	{0,-1},
	{0,1},
};

pair<int,int> addPi(pair<int,int> a, pair<int,int> b) {
	return {a.first+b.first, a.second + b.second};
}

bool inBounds(pair<int,int> pos, int r, int c) {
	return pos.first>=0 && pos.first<r && pos.second>=0 && pos.second<c; 
}

int solve(int r, int c, vector<vector<char>> grid) {
	pair<int,int> start = {0,0}, goal = {r-1,c-1};
	vector<vector<bool>> vis(r, *(new vector<bool>(c)));
	deque<pair<pair<int,int>, int>> dq;
	dq.push_back({start,1});
	vis[start.first][start.second] = true;
	
	while (!dq.empty()) {
		pair<pair<int,int>, int> back = dq.back();
		dq.pop_back();

		if (back.first == goal) {
			return back.second;
		}

		switch(val(back.first, grid)) {
			case '+':
				for (pair<int,int> dir : allDir) {
					pair<int,int> next = addPi(back.first, dir);
					if (inBounds(next,r,c)) {
						if (!vis[next.first][next.second]) {
							if (val(next,grid) != '*') {
								dq.push_front({next,back.second+1});
							}
							vis[next.first][next.second]=true;
						}
					}
				}
				break;
			case '|':
				for (pair<int,int> dir : upDown) {
					pair<int,int> next = addPi(back.first, dir);
					if (inBounds(next,r,c)) {
						if (!vis[next.first][next.second]) {
							if (val(next,grid) != '*') {
								dq.push_front({next,back.second+1});
							}
							vis[next.first][next.second]=true;
						}
					}
				}
				break;
			case '-':
			for (pair<int,int> dir : leftRight) {
					pair<int,int> next = addPi(back.first, dir);
					if (inBounds(next,r,c)) {
						if (!vis[next.first][next.second]) {
							if (val(next,grid) != '*') {
								dq.push_front({next,back.second+1});
							}
							vis[next.first][next.second]=true;
						}
					}
				}
				break;
		}
	}
	return -1;

}

int main() {
	int t; cin>>t;
	int ans[t];
	for (int i=0; i<t; i++) {
		int r,c; cin>>r>>c;
		vector<vector<char>> grid(r, *(new vector<char>(c)));
		for (int y=0; y<r; y++) {
			for (int x=0; x<c; x++) {
				cin>>grid[y][x];
			}
		}
		ans[i]=solve(r,c,grid);
	}
	for (int i : ans) cout << i << endl;
}