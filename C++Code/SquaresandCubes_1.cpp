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


ll solve(ll n) {
	ll c=0;
	unordered_map<ll,bool> map; 
	for (int i=1; i<=sqrt(n); i++) {
		ll a=i*i;
		ll b=a*i;
		if (a<=n) 
			if(map[a]==false) {
				c++;
				map[a]=true;
			}
		if (b<=n)
			if (map[b]==false) {
				c++;
				map[b]=true;
			}
	}
	return c;
}

int main() {
	int t; cin>>t;
	vector<ll> v;
	FOR(i,t) {
		ll n; cin>>n;
		v.PB(solve(n));
	}
	FOR(i,t) {
		cout << v[i] << endl;
	}
}