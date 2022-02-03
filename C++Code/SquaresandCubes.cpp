#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


ll solve(ll n) {
	ll c;
	for (int i=1; i<=sqrt(n); i++) {
		c+=(i*i<n)+(i);
	}
}

int main() {
	int t; cin>>t;
	for (int i=0; i<t; i++) {
		ll n; cin>>n;
		cout << solve(n) << endl;
	}
}