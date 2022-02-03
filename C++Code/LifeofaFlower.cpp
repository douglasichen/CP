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


int solve(vi v) {
	int h=0;
	for (int i=0; i<v.size(); ++i) {
		if (i>0) if (v[i]==v[i-1] && !v[i]) return h;
		if (i>1) if(v[i]==v[i-1] && v[i]) h+=4;
		if (v[i]) h++;
	}
	return h;
}

int main() {
	int t; cin>>t;
	FOR (i,t) {
		int n; cin>>n;
		vi v(n);
		FOR (o, n) cin>>v[o];
		cout << solve(v) << endl;
	}
}