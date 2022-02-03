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

int m,n;
vector<vi> room;
unordered_map<int,vector<pi>> valToLocs;

void printPi(pi p) {
	cout << p.F << ' ' << p.S << endl;
}

bool dfs() {
	vector<vector<bool>> visited(m+1,*(new vector<bool>(n+1)));
	pi goal={1,1};

	deque<pi> q;
	q.PB(MP(m,n));

	while (!q.empty()) {
		pi back = q.back();
		q.pop_back();
		if (back==goal) return true;

		visited[back.F][back.S]=true;
		int target = back.F*back.S;
		vector<pi> can = valToLocs[target];
		
		for (pi p : can) {
			if (!visited[p.F][p.S]) {
				q.push_back(p);
			}
		}
	}

	return false;
}



int main() {
	cin>>m>>n;
	room = *(new vector<vi>(m+1,*(new vi(n+1))));
	FOR(y,m) {
		FOR(x,n) {
			cin>>room[y+1][x+1];
			valToLocs[room[y+1][x+1]].PB(MP(y+1,x+1));
		}
	}

	bool ans = dfs();
	cout << (ans ? "yes" : "no") << endl;
}