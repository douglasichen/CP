#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(n) for(int i = 0; i < n; ++i)

int n;
pi goal;

int cont = 0;

bool blocked(pi pos, vector<vi> visited) {
	if (pos.F<0 || pos.F>n-1 || pos.S<0 || pos.S>n-1) return true;
	if (visited[pos.F][pos.S]) return true;
	return false;
}

pi add(pi a, pi b) {
	return {a.F+b.F,a.S+b.S};
}

vector<pi> getNewDirs(pi pos, vector<vi> visited) {
	vector<pi> rawDirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	vector<pi> dirs;
	for (int i=0; i<4; i++) {
		if (!blocked(add(pos,rawDirs[i]), visited)) {
			dirs.PB(rawDirs[i]);
		}
	}
	return dirs;
}

string sPos(pi pos) {
	return '{' + to_string(pos.F) + ',' + to_string(pos.S) + '}'; 
}

void solve(pi pos, vector<pi> dirs, vector<vi> visited) {
	visited[pos.F][pos.S] = 1;
	if (pos==goal) {
		cont++;
		return;
	}
	vector<pi> newPoses;
	
	for (int i=0; i<dirs.size(); i++) {
		newPoses.PB(add(pos,dirs[i]));
	}
	cout<<sPos(pos)<<": ";
	for (int i=0; i<newPoses.size(); i++) {
		cout << sPos(newPoses[i])<<' ';
	}
	cout<<endl;
	for (int i=0; i<newPoses.size(); i++) {
		solve(newPoses[i], getNewDirs(newPoses[i],visited), visited);
	}
}

int main() {
	cin>>n;
	goal = {n-1, n-1};
	vector<vi> visited(n, *(new vi(n)));
	solve({0,0},{{1,0}},visited);
	cout<<cont<<endl;
}