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


int solve(int n, vi v) {
	int ans=1;
	for (int i=0; i<n; i++) {
		if (v[i]) {
			ans++;
			if (v[i-1]==1) ans+=4;
		}
		else {
			if (i>0) {
				if (v[i-1]==0) return -1;
			}
		}
	}
	return ans;
}

int main() {
	int t; cin>>t;
	vi ans;
	FOR(i,t) {
		int n; cin>>n;
		vi v(n);
		FOR(o,n) cin>>v[o];
		ans.PB(solve(n,v));
	}
	for (int i : ans) cout << i << endl;
}