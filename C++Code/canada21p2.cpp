#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	vector<vector<int>> A(N,vector<int>(3));
	vector<vector<vector<vector<int>>>> G(101,vector<vector<vector<int>>>(101,vector<vector<int>>(101,{INT_MAX,INT_MAX}))); // dis, j
	for (int i=0; i<N; i++) cin>>A[i][0]>>A[i][1]>>A[i][2];
	
	deque<vector<int>> dq;
	for (int i=0,x,y,z; i<Q; i++) {
		cin>>x>>y>>z;
		if (G[x][y][z][1]>i) G[x][y][z]={0,i};
	}
	for (int x=1; x<=100; x++)
		for (int y=1; y<=100; y++)
			for (int z=1; z<=100; z++)
				if (!G[x][y][z][0])
					dq.push_back({x,y,z,0});

	vector<vector<int>> dirs={
		{1,0,0},
		{-1,0,0},
		{0,1,0},
		{0,-1,0},
		{0,0,1},
		{0,0,-1}
	};
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		int dis=back[3];
		for (vector<int> dir : dirs) {
			vector<int> nxt={back[0]+dir[0],back[1]+dir[1],back[2]+dir[2]};
			bool in=1;
			for (int i : nxt) if (i<0 || i>100) in=0;
			vector<int> v=G[nxt[0]][nxt[1]][nxt[2]];
			if (in && dis<=v[0]) {
				
			}
		}
	}
}