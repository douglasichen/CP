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


ll fastExp(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b&1) ans *= a;
		a *= a;
		b>>=1;
	} 
	return ans;
}

int main() {
	ll a,b; cin>>a>>b;
	ll ans = fastExp(a,b);
	cout << ans << endl;
}