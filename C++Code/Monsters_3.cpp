#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<bool>> G;
vector<vector<int>> D;
vector<vector<char>> frm;
deque<vector<int>> dq;
vector<int> pPos;
vector<vector<int>> dirs={
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};
vector<char> lets={'D','U','R','L'};

bool inBounds(vector<int> a) {
	return a[0]>=0 && a[0]<N && a[1]>=0 && a[1]<M;
}

bool bfs(bool isP) {
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		if (isP) {
			if (back[0]==0 || back[0]==N-1 || back[1]==0 || back[1]==M-1) {
				cout << "YES" << endl;
				string ans="";
				while (back[0]!=pPos[0] || back[1]!=pPos[1]) {
					char c=frm[back[0]][back[1]];
					ans+=c;
					if (c=='D') back[0]--;
					else if (c=='U') back[0]++;
					else if (c=='R') back[1]--;
					else back[1]++;
				}
				cout << ans.size() << endl;
				reverse(ans.begin(),ans.end());
				cout << ans << endl;
				return true;
			}
		}
		for (int i=0; i<4; i++) {
			vector<int> dir=dirs[i];
			vector<int> nxt={dir[0]+back[0],dir[1]+back[1]};
			if (inBounds(nxt) && G[nxt[0]][nxt[1]] && D[back[0]][back[1]]+1<D[nxt[0]][nxt[1]]) {
				D[nxt[0]][nxt[1]]=D[back[0]][back[1]]+1;
				dq.push_front(nxt);
				if (isP) frm[nxt[0]][nxt[1]]=lets[i];
			}
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	G=vector<vector<bool>>(N,vector<bool>(M));
	D=vector<vector<int>>(N,vector<int>(M,1e9));
	frm=vector<vector<char>>(N,vector<char>(M));
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			char c; cin>>c;
			G[y][x]=c!='#';
			if (c=='A') pPos={y,x};
			else if (c=='M') {
				dq.push_back({y,x});
				D[y][x]=0;
			}
		}
	}
	bfs(false);
	dq.push_back(pPos);
	D[pPos[0]][pPos[1]]=0;
	if (!bfs(true)) {
		cout << "NO" << endl;
	}
}
