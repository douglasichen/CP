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

int solve(int s, int x, int y) {
	int a = s*x, b = s*y;
	return b - a;
}

int main() {
	int t; cin>>t;
	vi ans;
	FOR(i,t) {
		int s,x,y; cin>>s>>x>>y;
		ans.PB(solve(s,x,y));
	}
	for (int i : ans) cout << i << endl;
}