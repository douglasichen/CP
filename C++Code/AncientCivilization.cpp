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


int solve(int n, int l, vi v) {
	int ans = 0;
	FOR(i,l) {
		float p = 0;
		FOR(o,n) {
			p += v[o]&1;
			v[o] = v[o]>>1;
		}
		p = p / n;
		if (p>0.5) ans += pow(2,i);
	}
	return ans;
}

int main() {
	int t; cin>>t;
	vi v;
	FOR(i,t) {
		int n,l; cin>>n>>l;
		vi nv(n);
		FOR (o,n) cin>>nv[o];
		v.PB(solve(n,l,nv));
	}
	for (int i : v) {
		cout << i << endl;
	}
}