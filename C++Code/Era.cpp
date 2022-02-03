#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

void solve(int n, vi v) {
	ll c = 0;
	for (int i=0; i<n-1; i++) {
		if (v[i+1] < v[i]) break;
		ll add = v[i+1]-v[i]-1;
		if (add>0) c+=add;
	}
	if (v[0]>1) c += v[0]-1;
	cout << c << endl;
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