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

bool inCircle(pi p, int r) {
	return sqrt(p.F*p.F + p.S*p.S) <= r+1;
}

void printPi(pi p) {
	cout << p.F << ' ' << p.S << endl;
}

ll solve(int r) {
	ll sum=0;
	pi p = {2,r+1};
	
	for (int x=2; x<=r+1; x++) {
		p = {x,p.S};
		for (int y=p.S; !inCircle(p,r) && y>=1; y--) {
			printPi(p);
			sum+=(r-p.F);
			p = {p.F,p.S-1};
		}
	}

	return (2*r+1)*(2*r+1)-sum*4;
}

int main() {
	int n;
	while (cin>>n) {
		if (n==0) break;
		cout << solve(n) << endl;
	}
}