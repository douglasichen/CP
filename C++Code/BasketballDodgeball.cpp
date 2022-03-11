#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> A,B;

vector<int> farA={0,0},farB{0,0};

vector<int> subV2(vector<int> a, vector<int> b) {
	return {a[0]-b[0], a[1]-b[1]};
}

bool inRange(vector<int> from, vector<int> to, int rad) {
	vector<int> dif=subV2(to,from);
	int dis=dif[0]*dif[0] + dif[1]*dif[1];
	int maxDis=rad*rad;

	return dis<=maxDis;
}

int bfs(vector<vector<int>> players, int start) {
	int n=players.size();
	vector<int> vis(n);
	deque<vector<int>> dq;	// node, distance
	
	dq.push_back({start,0});
	vis[start]=1;

	while(dq.size()) {
		vector<int> back=dq.back(); dq.pop_back();
		
		int fromNum=back[0], dis=back[1];
		vector<int> fromData=players[fromNum], fromPos={fromData[0], fromData[1]};
		int r=fromData[2];

		if (r==9001) return dis;

		for (int i=0; i<n; i++) {
			// init and visited
			int pNum=i, pDis=dis+1;
			if (vis[pNum]) continue;
			
			// continue search cycle
			vector<int> player=players[i], playerPos={player[0],player[1]};
			if (inRange(fromPos,playerPos,r)) {
				dq.push_front({i,pDis});
				vis[pNum]=1;
			}
		}
	}
	return INT_MAX;
}

int solve() {
	int abfs=bfs(A,farA[0]), bbfs=bfs(B,farB[0]);
	return (abfs==bbfs ? 0 : abfs<bbfs ? 1 : -1);
}

int main() {
	cin>>N>>M;
	A=*(new vector<vector<int>>(N));
	B=*(new vector<vector<int>>(M));

	for (int i=0; i<N; i++) {
		int x,y,r; cin>>x>>y>>r;
		A[i]={x,y,r};

		// starting
		if (A[i][1]>=farA[1])
			farA={i,A[i][1]};
	}
	for (int i=0; i<M; i++) {
		int x,y,r; cin>>x>>y>>r;
		B[i]={x,y,r};

		// starting
		if (B[i][1]>=farB[1])
			farB={i,B[i][1]};
	}

	int ans=solve();
	if (ans==0) cout << "SUDDEN DEATH";
	else if (ans==1) cout << "We are the champions!";
	else cout << ":'(";
	cout << endl;
}