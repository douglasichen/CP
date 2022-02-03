#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

bool prime(int n) {
	if (n%2==0) return false;
	for (int i=3; i<=sqrt(n); i+=2) if (n%i==0) return false;
	return true;
}

bool sorter(pi a, pi b) {
	return a.S<b.S;
}

void solve(int n, vi v) {
	vector<pi> vv(n);
	for (int i=0; i<n; i++) vv[i] = {i,v[i]};
	sort(vv.begin(), vv.end());
	
	int sum=0; for (int i=0; i<n; i++) sum+=v[i];

	vi ans(n); for (int i=1; i<=n; i++) ans[i]=i;
	for (int i=0; i<n; i++) {
		if (prime(sum)) {
			if ()
		}
	}
}

int main() {
	int t; cin>>t;
	for (int i=0; i<t; i++) {
		int n; cin>>n;
		vi v(n);
		for (int o=0; o<n; o++) cin>>v[o];
		solve(n,v);
	}
}