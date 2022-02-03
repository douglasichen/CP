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


bool solve(ll a, ll b, ll c) {
	if (c > a) return 0;
	a -= c;

	if (a%2!=0) {
		return 0;
	}

	
	if (c>0) {
		return 1;
	}
	c=0;
	b=b%2;
	if (b!=0) {
		if (a>=2 && a%2==0) return 1;
		return 0;
	}
	else {
		if (a%2==0) return 1;
		return 0;
	}

}

int main() {
	int t; cin>>t;
	FOR(i,t) {
		ll a,b,c;
		cin>>a>>b>>c;
		bool ans = solve(a,b,c);
		cout << (ans ? "YES" : "NO") << endl;
	}
}