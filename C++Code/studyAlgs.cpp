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

ll fastExp(ll a, ll b) {
	ll r=1;
	while(b) {
		if (b&1) r*=a;
		a*=a;
		b>>=1;
	}
	return r;
}

void bits() {
	ll a,b; cin>>a>>b;
	cout << fastExp(a,b) << endl;
}

int n, t[1000000];
void buildSegmentTree(int a[], int v, int tl, int tr) {
	if (tl==tr) {
		t[v] = a[tl];
	}
	else {
		int mid = (tl+tr)/2;
		buildSegmentTree(a, v*2, tl, mid);
		buildSegmentTree(a, v*2+1, mid+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

void segTree() {
	int n; cin>>n;
	int a[n];
	FOR(i,n) cin>>a[i];
	buildSegmentTree(a, 0, 0, n-1);
}

int main() {
	// bits();
	segTree();
}