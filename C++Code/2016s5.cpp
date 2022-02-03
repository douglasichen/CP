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

ll n, t;
string con;
vector<ll> alive;


ll correct(int i) {
	if (i<0) return i+n;
	if (i>n-1) return i-n;
	return i;
}

string solve() {
	vector<ll> newAlive;
	string newCon(n,'0');
	for (ll i : alive) {
		// cout << "i: " << i << endl;
		ll a = correct(i-2);
		ll b = correct(i+2);
		// cout << "\ta: "<<a << endl;
		// cout << "\tb: "<<b << endl;
		if (con[a]=='0') {
			ll place = correct(i-1);
			newAlive.PB(place);
			newCon[place]='1';
		}
		if (con[b]=='0') {
			ll place = correct(i+1);
			newAlive.PB(place);
			newCon[place]='1';
		}
	}
	alive = newAlive;
	return newCon;
}

void pat(ll times) {
	for (ll i=1; i<=times; i++) {
		con = solve();
	}
}

int main() {
	cin>>n>>t;
	con="";
	for (ll i=0; i<n; i++) {
		char inp; cin>>inp;
		con+=inp;
		if (inp=='1') alive.PB(i);
	}
	
	unordered_map<size_t,pi> m;
	hash<string> hasher;
	m[hasher(con)] = {1,0};
	for (ll i=1; i<=t; i++) {
		con = solve();

		size_t h = hasher(con);
		if (m[h].F) {
			ll times = i - m[h].S;
			pat((n%times)-1);
			break;
		}

		m[h] = {1,i};
	}
	cout << con << endl;
}