#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

int h,w;
vector<vector<char>> grid;
vector<vector<vector<pi>>> tree;
vector<vector<bool>> visited;
vector<vi> ds;
pi pos;
vector<pi> e;
vector<pi> dirs = {
	{1,0},{-1,0},{0,-1},{0,1}
};

void solve() {

}

pi addPi(pi a, pi b) {
	return {a.F+b.F, a.S+b.S};
}

pi fd(pi p) {
	pi dir={0,0};
	switch (grid[p.F][p.S]) {
		case 'R':
		dir={0,1};
		break;
		case 'L':
		dir={0,-1};
		break;
		case 'U':
		dir={-1,0};
		break;
		case 'D':
		dir={1,0};
		break;
	}
	if (dir.F!=0 && p.S!=0) grid[p.F][p.S]='W';
	return addPi(p,dir);
}

void pg() {
	for (int y=0; y<grid.size(); ++y) {
		for (int x=0; x<grid[0].size(); ++x) {
			cout<<grid[y][x];
		}
		cout<<endl;
	}
}

void printPi(pi p) {
	cout<<p.F<<' '<<p.S<<endl;
}

void spread(pi p, int d) {
	// printPi(p);
	p = fd(p);
	if (grid[p.F][p.S]=='W') return;
	if (grid[p.F][p.S]=='.') {
		ds[p.F][p.S]=d;
		// cout<<d<<endl;
		grid[p.F][p.S]='W';
	}
	// pg();
	for (pi dir : dirs) {
		pi newLoc = addPi(p,dir);
		spread(newLoc,d+1);
	}
}


void setTree(pi pos, int step) {
	visited[pos.F][pos.S] = true;
	for (pi dir : dirs) {
		pi nextPos = addPi(pos, dir);
		if (grid[nextPos.F][nextPos.S]!='W') {
			int times = 0;
			while (grid[nextPos.F][nextPos.S]!='.') {
				if (times>=4) break;
				nextPos = fd(nextPos);
				++times;
			}
			if (grid[nextPos.F][nextPos.S]!='.') continue;
			// if (visited[nextPos.F][nextPos.S])
			if (step<ds[nextPos.F][nextPos.S] || ds[nextPos.F][nextPos.S] == -1) {
				tree[pos.F][pos.S].PB(nextPos);
				ds[nextPos.F][nextPos.S] = step+1;
				// cout << step << " > " << ds[nextPos.F][nextPos.S] << " so adding edge from ";
				// printPi(pos);
				// cout << " to ";
				// printPi(nextPos);
				// cout<<endl;
			}
		}
	}
	for (pi p : tree[pos.F][pos.S]) {
		setTree(p, step+1);
	}
}

void travTree(pi pos, int step) {
	if(ds[pos.F][pos.S]==-1) ds[pos.F][pos.S] = step;
	for (pi p : tree[pos.F][pos.S]) {
		travTree(p, step+1);
	}
}

int main() {
	vector<pi> cams;
	cin>>h>>w;
	grid = *(new vector<vector<char>>(h, *(new vector<char>(w))));
	tree = *(new vector<vector<vector<pi>>>(h, *(new vector<vector<pi>>(w))));
	visited = *(new vector<vector<bool>>(h, *(new vector<bool>(w))));
	ds = *(new vector<vi>(h, *(new vi(w,-1))));
	for (int y=0; y<h; ++y) {
		for (int x=0; x<w; ++x) {
			cin>>grid[y][x];
			if (grid[y][x]=='C') {
				cams.PB({y,x});
				grid[y][x]='W';
			}
			if (grid[y][x]=='S') pos={y,x};
			if (grid[y][x]=='.') e.PB({y,x});
		}
	}
	for (pi cam : cams) {
		for (pi dir : dirs) {
			pi loc = addPi(cam,dir);
			while (grid[loc.F][loc.S]!='W') {
				if (grid[loc.F][loc.S]=='.') grid[loc.F][loc.S]='W';
				loc = addPi(loc,dir);
			}
		}
	}
	// pg();
	// spread(pos,0);

	setTree(pos, 0);

	// travTree(pos, 0);

	for (pi p : e) {
		cout << ds[p.F][p.S] << endl;
	}
}