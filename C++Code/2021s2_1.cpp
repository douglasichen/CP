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
	ll n,m,k; cin>>n>>m>>k;
	vector<ll> rows, cols;
	FOR(i,k) {
		char c; cin>>c;
		ll pos; cin>>pos;
		if (c=='R') rows.PB(pos);
		else cols.PB(pos);
	}

	unordered_map<ll, ll> rCount, cCount;
	vector<ll> initR, initC; 
	for (ll r : rows) {
		if (!rCount[r]) initR.PB(r);
		rCount[r]++;
	}
	for (ll c : cols) {
		if (!cCount[c]) initC.PB(c);
		cCount[c]++;
	}
	
	vector<ll> finR, finC;
	for (ll r : initR) {
		if (rCount[r]%2!=0) finR.PB(r);
	}
	for (ll c : initC) {
		if (cCount[c]%2!=0) finC.PB(c); 
	}

	ll ans=finR.size()*m;
	ll gRow = finR.size();

	// cout << "ans: " << ans;
	// cout << endl;
	// for (ll r : finR) {
	// 	cout << "R: " << r << endl;
	// }
	// for (ll c : finC) {
	// 	cout << "C: " << c << endl;
	// }
	
	for (ll c : finC) {
		ans -= gRow;
		ans += (n - gRow);
	}
	cout << ans << endl;
	
}
