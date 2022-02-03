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
	int n; cin>>n;
	vector<pi> v;
	FOR(i,n) {
		ll t,x; cin>>t>>x;
		v.PB(MP(t,x));
	}
	sort(v.begin(), v.end());
	double maxSpd=0;
	FOR(i,n-1) {
		ll t = v[i+1].F - v[i].F;
		ll dis = abs(v[i+1].S - v[i].S);
		double spd = (double)dis/(double)t;
		if (spd>maxSpd) maxSpd = spd;
	}
	cout << maxSpd << endl;
}