#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	vector<vector<vector<vector<int>>>> G(101,vector<vector<vector<int>>>(101,vector<vector<int>>(101,{(int)1e6+1,(int)1e6+1}))); // dis, j
	int N,Q; cin>>N>>Q;
	
	deque<vector<int>> dq;
	for (int i=0,x,y,z; i<N; i++) {
		cin>>x>>y>>z;
		if (i<G[x][y][z][1]) G[x][y][z]={0,i};
	}
	for (int x=0; x<=100; x++) 
		for (int y=0; y<=100; y++) 
			for (int z=0; z<=100; z++) 
				if (G[x][y][z][0]==0) 
					dq.push_back({x,y,z,0,G[x][y][z][1]});

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
		int dis=back[3], j=back[4];
		for (vector<int> dir : dirs) {
			vector<int> nxt={back[0]+dir[0],back[1]+dir[1],back[2]+dir[2],dis+1,j};
			bool in=1;
			for (int i=0; i<3; i++) if (nxt[i]<0 || nxt[i]>100) in=0;
			if (in) {
				vector<int> v=G[nxt[0]][nxt[1]][nxt[2]];
				bool e=0;
                if (dis+1<v[0]) G[nxt[0]][nxt[1]][nxt[2]]={dis+1,j},e=1;
				else if (dis+1==v[0] && j<v[1]) G[nxt[0]][nxt[1]][nxt[2]][1]=j,e=1;
				if (e) dq.push_front(nxt);
			}
		}
	}
	for (int i=0,x,y,z; i<Q; i++) {
		cin>>x>>y>>z;
		cout << G[x][y][z][1]+1 << endl;
	}

}