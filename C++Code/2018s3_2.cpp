#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef vector<vector<int>> vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(x,n) for(int x = 0; x < n; ++x)

#define printV(v) FOR(x,v.size()) cout<<v[x]<<' '; cout<<endl;


int h,w; 
bool dead = false;
vector<vector<char>> graph;
vector<pi> es;
vector<pi> cams;
vector<vector<ll>> ds;

vector<pi> dirs = {
	{1,0},{-1,0},{0,1},{0,-1}
};

void solve() {

}

pi addPi(pi a, pi b) {
	return {a.F + b.F, a.S + b.S};
}

void spreadCam(pi cam) {
	// graph[cam.F][cam.S] = 'W';
	for (pi dir : dirs) {
		pi nPos = addPi(cam, dir);
		while (graph[nPos.F][nPos.S] != 'W') {
			if (graph[nPos.F][nPos.S]=='.') graph[nPos.F][nPos.S] = 'P';
			if (graph[nPos.F][nPos.S]=='S') {
				dead = true;
				return;
			}
			nPos = addPi(nPos, dir);
		}
	}
}

void print2dV(vector<vector<char>> vv) {
	for (vector<char> v : vv) {
		for (char i : v)
			cout << i;
		cout << endl;
	}
}

pi conv(pi p) {
	switch (graph[p.F][p.S]) {
		case 'U': return addPi(p,{-1,0});
		case 'D': return addPi(p,{1,0});
		case 'R': return addPi(p,{0,1});
		case 'L': return addPi(p,{0,-1});
	}
	return p;
}

void printPi(pi p) {
	cout << p.F << ',' << p.S << endl;
}

pi thrConv(pi nPos) {
	vector<vector<bool>> visited(h, *(new vector<bool>(w)));
	while (!visited[nPos.F][nPos.S] && graph[nPos.F][nPos.S] != 'W' && graph[nPos.F][nPos.S] != '.') {
		visited[nPos.F][nPos.S] = true;
		nPos = conv(nPos);
	}
	// printPi(nPos);
	return nPos;
}



void bfs(pi start) {
	// graph[start.F][start.S] = 'W';
	// print2dV(graph);
	deque<pair<pi,int>> dq;
	dq.push_back({start, 0});
	while (!dq.empty()) {
		pair<pi,int> back = dq.back();
		// printPi(back.F);
		ds[back.F.F][back.F.S] = (ll)back.S;
		// if (graph[back.F.F][back.F.S] == '.') graph[back.F.F][back.F.S] = 'W';
		dq.pop_back();
		// cout << dq.size() << endl;
		for (pi dir : dirs) {
			pi nPos = addPi(back.F, dir);
			if (graph[nPos.F][nPos.S]!='W'&&graph[nPos.F][nPos.S]!='.') nPos = thrConv(nPos);
			if (graph[nPos.F][nPos.S]=='.') {
				graph[nPos.F][nPos.S] = 'W';
				dq.push_front({nPos,back.S+1});
			}
		}
	}
}

int main() {
	cin>>h>>w;
	graph = *(new vector<vector<char>>(h, *(new vector<char>(w))));
	ds = *(new vector<vector<ll>>(h, *(new vector<ll>(w,-1))));

	pi start;
	FOR(y,h) {
		FOR(x,w) {
			cin >> graph[y][x];
			switch(graph[y][x]){
				case 'S':
					start = {y,x};
					break;
				case '.':
					es.PB({y,x});
					break;
				case 'C':
					cams.PB({y,x});
					break;
			}
		}
	}

	for (pi cam : cams) {
		spreadCam(cam);
	}
	

	if (!dead && es.size()>0) bfs(start);

	for (pi e : es) {
		cout << ds[e.F][e.S] << endl;
	}
}