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


ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll solve(int n, vector<ll> v) {
	vector<ll> odd,even;
	FOR(i,v.size()) {
		if ((i+1)%2==1) {
			odd.PB(v[i]);
		}
		else {
			even.PB(v[i]);
		}
	}
	ll oddGcd=odd[0], evenGcd=even[0];
	for (int i=1; i<odd.size(); i++) {
		oddGcd = gcd(oddGcd,odd[i]);
	}
	for (int i=1; i<even.size(); i++) {
		evenGcd = gcd(evenGcd,even[i]);
	}

	ll ans=0;
	if (oddGcd!=evenGcd) {
		
		bool ok1=1,ok2=1;
		FOR(i,even.size()) {
			if (even[i]%oddGcd==0) {
				ok1=0;
				break;
			}
		}
		FOR(i,odd.size()) {
			if (odd[i]%evenGcd==0) {
				ok2=0;
				break;
			}
		}
		if (ok1) ans = oddGcd;
		if (ok2) ans = evenGcd;	
	}

	// cout << oddGcd << ' ' << evenGcd << endl;

	return ans;
}

int main() {
	
	int t; cin>>t;
	vector<ll> vv;
	FOR(i,t) {
		int n; cin>>n;
		vector<ll> v(n);
		FOR(o,n) cin>>v[o];
		vv.PB(solve(n,v));
	}	
	FOR(i,t) {
		cout << vv[i] << endl;
	}
}