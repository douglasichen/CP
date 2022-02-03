#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define uMap unordered_map
#define vec vector
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(x,n) for(int x = 0; x < n; ++x)

int n,m;
vec<vec<char>> graph;
vec<vec<int>> ansG;
vec<pi> cams;
vec<pi> emps;


pi start;

vec<pi> dirs = {
	{0,1},
	{1,0},
	{-1,0},
	{0,-1},
};


void print2d(vec<vec<char>> g) {
	for (vec<char> r : g) {
		for (char i : r) cout << i;
		cout << endl;
	}
}

pi addPi(pi a, pi b) {
	return {a.F + b.F, a.S + b.S};
}

char inG(pi p) {
	return graph[p.F][p.S];
}

void setG(pi p, char c) {
	graph[p.F][p.S] = c;
}

void spreadCam(pi cam) {
	setG(cam,'P');
	for (pi dir : dirs) {
		pi next = addPi(cam,dir);
		while (inG(next) != 'W') {
			if (inG(next)=='.') {
				setG(next,'P');
			}
			next = addPi(next,dir);
		}
	}
}

void printPi(pi p) {
	cout << p.F << ' ' << p.S << endl;
}


pi conv(pi pos) {
	vec<vec<bool>> vis(n, *(new vec<bool>(m)));
	while (!vis[pos.F][pos.S] && (inG(pos) == 'U' || inG(pos) == 'D' || inG(pos) == 'R' || inG(pos) == 'L')) {
		vis[pos.F][pos.S] = true;
		switch(inG(pos)) {
			case 'U':
				pos = addPi(pos,{-1,0});
				break;
			case 'D':
				pos = addPi(pos,{1,0});
				break;
			case 'R':
				pos = addPi(pos,{0,1});
				break;
			case 'L':
				pos = addPi(pos,{0,-1});
				break;
		}
	}
	return pos;
}


void solve() {
	setG(start,'W');
	deque<pair<pi,int>> q;
	q.PB({start,0});
	while (!q.empty()) {
		pair<pi,int> back = q.back();
		q.pop_back();
		
		ansG[back.F.F][back.F.S]=back.S;

		for (pi dir : dirs) {
			pi next = addPi(back.F,dir);
			if (inG(next)!='W' && inG(next)!='P') {
				
				next = conv(next);
				if (inG(next)!='.') continue;

				setG(next,'W');
				q.push_front({next,back.S+1});
			}
		}
	}
}




int main() {
	cin>>n>>m;
	vec<vec<char>> temp(n, *(new vec<char>(m)));
	graph = temp;
	ansG = *(new vec<vec<int>>(n, *(new vec<int>(m,-1))));
	FOR(y,n) {
		FOR(x,m) {
			char inp; cin>>inp;
			graph[y][x] = inp;

			switch (inp) {
				case 'S':
					start = {y,x};
					break;
				case 'C':
					cams.PB({y,x});
					break;
				case '.':
					emps.PB({y,x});
					break;
			}
		}
	}
	for (pi cam : cams) {
		spreadCam(cam);
	}
	// print2d(graph);

	solve();

	for (pi emp : emps) {
		cout << ansG[emp.F][emp.S] << endl;
	}
}