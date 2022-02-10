#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allD {
	{1,0},
	{0,1},
	{-1,0},
	{0,-1},
};

vector<vector<int>> hD {
	{0,1},
	{0,-1},
};

vector<vector<int>> vD {
	{1,0},
	{-1,0},
};

vector<int> add(vector<int> a, vector<int> b) {
	return {a[0]+b[0], a[1]+b[1]};
}


int solve(int n, int m, vector<vector<char>> g) {
	unordered_map<int,unordered_map<int,bool>> vis;
	deque<vector<int>> dq;
	vis[0][0]=1;
	dq.push_back({0,0,1});	// pos,dis

	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		vector<int> pos={back[0],back[1]};
		int dis=back[2];
		
		if (pos[0]==n-1 && pos[1]==m-1)
			return dis;

		char val=g[pos[0]][pos[1]];
		vector<vector<int>> avalDirs;
		switch (val) {
			case '+':
			avalDirs=allD;
			break;
			case '-':
			avalDirs=hD;
			break;
			case '|':
			avalDirs=vD;
			break;
		}

		for (vector<int> dir : avalDirs) {
			vector<int> nextPos=add(pos,dir);
			if (nextPos[0]<0 || nextPos[0]>=n || nextPos[1]<0 || nextPos[1]>=m) continue;
			if (g[nextPos[0]][nextPos[1]]!='*') {
				if (!vis[nextPos[0]][nextPos[1]]) {
					dq.push_front({nextPos[0],nextPos[1],dis+1});
					vis[nextPos[0]][nextPos[1]]=1;
				}
			}
		}
	}
	return -1;
}

int main() {
	int t; cin>>t;
	int ans[t];
	
	for (int i=0; i<t; i++) {
		int n,m; cin>>n>>m;
		vector<vector<char>> g(n,*(new vector<char>(m)));
		for (int y=0; y<n; y++) {
			for (int x=0; x<m; x++) {
				cin>>g[y][x];
			}
		}
		ans[i]=solve(n,m,g);
	}
	for (int i : ans) cout << i << endl;
}