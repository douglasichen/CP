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


ll solve(ll n, ll x) {
	int dir = 1;
	if (x&1==0) {
		if (n&1==0) dir = -1;
	}
	else {
		if (n&1) dir = -1;
	}
	return x + dir * (ll)(ceil((float)n/2.0));
}

int main() {
	int t; cin>>t;
	vector<ll> v;
	FOR(i,t) {
		ll x,n; cin>>x>>n;
		v.PB(solve(n,x));
	}
	FOR(i,t) cout << v[i] << endl;
}