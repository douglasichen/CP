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

vector<vector<ll>> ppl;

ll minTime(ll c) {
	ll time=0;
	for (vector<ll> p : ppl) {
		ll pos=p[0];
		ll spd=p[1];
		ll range=p[2];
		if (c <= pos+range && c >= pos-range) continue;
		int dir = (c > pos ? 1 : -1);
		pos = pos + range*dir;
		ll dis = abs(c-pos);
		ll t = dis*spd;
		time+=t;
		// cout << t << endl;
	}
	return time;
}

int main() {
	ll n; cin>>n;
	vector<vector<ll>> v(n, *(new vector<ll>(3)));
	ppl = v;
	FOR(i,n) {
		cin >> ppl[i][0] >> ppl[i][1] >> ppl[i][2];
	}
	ll a=0, b=1e9;
	ll ans=minTime(a);
	// cout << minTime(1) << endl;
	// for (int i=0; i<100; i++) {
	// 	cout << minTime(i) << ' ';
	// }
	// cout << endl;

	int c=0;
	while (abs(a-b)>1) {
		// c++; if(c>100) break;
		ll mid = (a+b)/2;
		ll left = minTime(mid-1), right = minTime(mid);
		ans = min(left,right);
		// cout << left << ' ' << right << endl;
		if (left < right) b = mid;
		else if (left > right) a = mid;
		else break;
	}
	cout << ans << endl;
}