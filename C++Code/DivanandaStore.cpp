#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


void solve(int n, int l, int r, int k, vi a) {
	sort(a.begin(), a.end());
	int c=0;
	for (int i=0; i<n; i++) {
		if (a[i]>=l && a[i]<=r && k-a[i]>=0) {
			k-=a[i];
			c++;
		}
	}

	cout << c << endl;
}

int main() {
	int t; cin>>t;
	for (int i=0; i<t; i++) {
		int n,l,r,k; cin>>n>>l>>r>>k;
		vi a(n);
		for (int o=0; o<n; o++) cin>>a[o];
		solve(n,l,r,k,a);
	}
}