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

int main() {
	int n; cin>>n;
	vi v(n);
	FOR(i,n) cin>>v[i];
	sort(v.begin(), v.end());
	vi ans;
	int incr=1;
	for (int i=ceil((float)n/2.0)-1; i>=0; i--) {
		ans.PB(v[i]);
		if (i+incr<v.size()) ans.PB(v[i+incr]);
		incr+=2;
	}
	for (int i : ans) cout << i << ' ';
	cout << endl;
}