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


int solve(int n, int m, int r, int c, vector<vector<char>> v) {
	r--; c--;
	if (v[r][c]=='B') return 0;
	
	bool hasBlack=false;
	for (vector<char> vc : v) {
		for (char c : vc) {
			if (c=='B') {
				hasBlack = true;
				break;
			}
		}
		if (hasBlack) break;
	}
	if (!hasBlack) return -1;
	
	bool rcBlack=false;
	for (int y=0; y<n; y++) {
		if (v[y][c]=='B') {
			rcBlack = true;
			break;
		}
	}
	if (!rcBlack) {
		for (int x=0; x<m; x++) {
			if (v[r][x]=='B') {
				rcBlack=true;
				break;
			}
		}
	}
	if (rcBlack) return 1;
	return 2;
}

int main() {
	int t; cin >> t;
	vi ans;
	FOR(i,t) {
		int n,m,r,c; cin>>n>>m>>r>>c;
		vector<vector<char>> v(n,*(new vector<char>(m)));
		FOR(y,n) {
			FOR(x,m) {
				cin>>v[y][x];
			}
		}
		ans.PB(solve(n,m,r,c,v));
	}
	for (int i : ans) {
		cout << i << endl;
	}
}