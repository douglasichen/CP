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


bool prime(int n) {
	for (int i=2; i<=sqrt(n); i++) {
		if (n%i==0) return false;
	}
	return true;
}

pi solve(int n) {
	int target = n*2;
	for (int i=2; i<=n; i++) {
		int a = i, b = target-i;
		if (prime(a)) {
			if (prime(b)) return {a,b};
		}
	}
	return {0,0};
}

int main() {
	int t; cin>>t;
	vector<pi> ans;
	FOR(i,t) {
		int n; cin>>n;
		ans.PB(solve(n));
	}
	for (pi p : ans) {
		cout << p.F << ' ' << p.S << endl;
	}
}