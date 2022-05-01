#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<vector<char>> G(N,vector<char>(M));
	vector<int> start,end;
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			cin>>G[y][x];
			if (G[y][x]=='A') start={y,x};
			if (G[y][x]=='B') end={y,x};
		}
	}
	vector<vector<int>> dirs={
		{0,1},
		{1,0},
		{0,-1},
		{-1,0}
	};
	vector<vector<char>> dir2Let={
		{0,'U',0},
		{'L',0,'R'},
		{0,'D',0}
	};
	vector<vector<vector<int>>> instr(N,vector<vector<int>>(M,{0,0}));
	vector<vector<bool>> vis(N,vector<bool>(M));
	deque<vector<int>> dq;
	dq.push_back(start);
	vis[start[0]][start[1]]=1;
	bool ok=0;
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		for (int i=0; i<4; i++) {
			vector<int> dir=dirs[i],nPos={back[0]+dir[0],back[1]+dir[1]};
			if (nPos[0]>=0 && nPos[0]<N && nPos[1]>=0 && nPos[1]<M && G[nPos[0]][nPos[1]]!='#' && !vis[nPos[0]][nPos[1]]) {
				dq.push_front(nPos);
				vis[nPos[0]][nPos[1]]=1;
				instr[nPos[0]][nPos[1]]=dirs[i];
				if (G[nPos[0]][nPos[1]]=='B') {
					ok=1;
					break;
				}
			}
		}
		if (ok) break;
	}
	vector<int> to=instr[end[0]][end[1]];
	if (to[0]==0 && to[1]==0) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		string ans="";
		vector<int> at=end;
		while (instr[at[0]][at[1]][0]!=0 || instr[at[0]][at[1]][1]!=0) {
			vector<int> dir=instr[at[0]][at[1]];
			ans+=dir2Let[dir[0]+1][dir[1]+1];
			at={at[0]-dir[0],at[1]-dir[1]};
		}
		cout << ans.size() << endl;
		for (int i=ans.size()-1; i>=0; i--) cout << ans[i];
		cout << endl;
	}
}
