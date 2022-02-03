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


void solve(vector<ll> v) {
	bool ans = 0;
	FOR (a,3) {
		ll sum=0;
		FOR (b,3) {
			if (a==b) continue;
			sum+=v[b];
		}
		if (v[a]==sum) {
			ans = true;
			break;
		}
	}

	ans=v[0]==v[1]||v[0]==v[2]||v[1]==v[2];

	cout << (ans ? "YES" : "NO") << endl;
}

int main() {
	int t; cin>>t;
	FOR(i,t) {
		ll a,b,c; cin>>a>>b>>c;
		solve({a,b,c});
	}
}