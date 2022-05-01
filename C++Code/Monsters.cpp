#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<bool>> G;
deque<vector<int>> dq;
vector<vector<int>> dirs={
	{0,1},
	{1,0},
	{-1,0},
	{0,-1}
};

vector<char> dLets={
	'R','D','U','L'
};

vector<int> add(vector<int> a, vector<int> b) {
	return {a[0]+b[0],a[1]+b[1]};
}

bool inBounds(vector<int> a) {
	return a[0]>=0 && a[0]<N && a[1]>=0 && a[1]<M;
}

void printV(vector<vector<int>> v) {
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			cout << v[y][x] << ' ';
		}
		cout << endl;
	}
}

void bfs(vector<vector<int>> &D, vector<vector<char>> &path) {
	vector<vector<bool>> vis(N,vector<bool>(M));
	deque<vector<int>> cpy=dq;
	while (!cpy.empty()) {
		vector<int> back=cpy.back();
		vis[back[0]][back[1]]=1;
		cpy.pop_back();
	}
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		vector<int> from={back[0],back[1]};
		int dis=back[2];
		D[from[0]][from[1]]=dis;
		for (int i=0; i<4; i++) {
			vector<int> dir=dirs[i],nxt=add(from,dir);
			if (inBounds(nxt) && G[nxt[0]][nxt[1]] && !vis[nxt[0]][nxt[1]]) {
				path[nxt[0]][nxt[1]]=dLets[i];
				vis[nxt[0]][nxt[1]]=1;
				nxt.push_back(dis+1);
				dq.push_front(nxt);
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	G=vector<vector<bool>>(N,vector<bool>(M));
	vector<int> myPos;
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			char c; cin>>c;
			G[y][x]=(c!='#');
			if (c=='M') dq.push_back({y,x,0});
			else if (c=='A') myPos={y,x};
		}
	}
	vector<vector<int>> MD(N,vector<int>(M,INT_MAX)),PD(N,vector<int>(M,INT_MAX));
	vector<vector<char>> path(N,vector<char>(M)),p=path;
	bfs(MD,p);
	dq.push_back({myPos[0],myPos[1],0});
	bfs(PD,path);

	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			if (MD[y][x]<=PD[y][x]) G[y][x]=0;
		}
	}

	vector<int> last;
	for (int y=1; y<N-1; y++) {
		if (G[y][0] && PD[y][0]<MD[y][0]) last={y,0};
		if (G[y][M-1] && PD[y][M-1]<MD[y][M-1]) last={y,M-1};
	}
	for (int x=1; x<M-1; x++) {
		if (G[0][x] && PD[0][x]<MD[0][x]) last={0,x};
		if (G[N-1][x] && PD[N-1][x]<MD[N-1][x]) last={N-1,x};
	}

	if (last.size()==0) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		string ans="";
		while (path[last[0]][last[1]]!=0) {
			char c=path[last[0]][last[1]];
			ans+=c;
			if (c=='R') last[1]--;
			else if (c=='L') last[1]++;
			else if (c=='D') last[0]--;
			else if (c=='U') last[0]++;
		}
		reverse(ans.begin(),ans.end());
		cout << ans.size() << endl;
		cout << ans << endl;
	}
}