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

bool good(pi a, pi b) {
	return a.F == b.F || a.S == b.S;
}

pi piAdd(pi a, pi b) {
	return MP(a.F+b.F, a.S+b.S);
}

void printPi(pi a) {
	cout << a.F << ' ' << a.S << endl;
}

int solve(int n, int m, pi pos, pi goal) {
	int ans=0;
	pi dir = {1,1};
	while (!good(pos,goal)) {
		pi nextPos = piAdd(pos,dir);
		if (nextPos.F>n || nextPos.F<0) {
			dir.F *= -1;
		}
		if (nextPos.S>m || nextPos.S<0) {
			dir.S *=-1;
		}
		pos = piAdd(pos,dir);
		// printPi(pos);
		ans++;
	}
	return ans;
}

int main() {
	int t; cin>>t;
	vi ans;
	FOR(i,t) {
		int n,m; cin>>n>>m;
		pi pos, goal; cin>>pos.F>>pos.S>>goal.F>>goal.S;
		ans.PB(solve(n,m,pos,goal));
	}
	for (int i : ans) {
		cout << i << endl;
	}
}