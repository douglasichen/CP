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


void solve() {

}

int main() {
	ll n,m,k; cin>>m>>n>>k;
	vector<ll> r,c;
	ll rCount=0, cCount=0;
	ll ans=0;
	unordered_map<ll,ll> rVis, cVis;
	FOR(i,k) {
		char ch; ll p; cin>>ch>>p;
		if (ch == 'R') {
			r.PB(p);
		}
		else {
			c.PB(p);
		}
	}
	vector<ll> rv, cv;
	FOR(i,r.size()) {
		if (rVis[r[i]]==0) rv.PB(r[i]);
		rVis[r[i]]++;
	}
	FOR(i,c.size()) {
		if (cVis[c[i]]==0) cv.PB(c[i]);
		cVis[r[i]]++;
	}
	FOR(i,rv.size()) {
		if (rVis[rv[i]]%2!=0) {
			rCount++;
			ans -= cCount;
			ans += (m - cCount);
		}
	}
	// cout << endl;
	FOR(i,cv.size()) {
		// cout << cv[i] << endl;
		if (cVis[cv[i]]%2!=0) {
			cCount++;
			ans -= rCount;
			ans += (n - rCount);
		}
	}
	cout << ans << endl;


}