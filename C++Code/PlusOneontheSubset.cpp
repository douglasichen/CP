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


int solve(int n, vi v) {
	int sum = 0;
	for (int i : v) sum+=i;
	sum /= v.size();
	cout << sum << endl;
	int ans=0;
	unordered_map<int,bool> found;
	for (int i : v) {
		if (!found[i]) {
			ans += i;
		}
		else {
			found[i]=true;
		}
	}
	return ans;
}

int main() {
	int t; cin>>t;
	FOR(i,t) {
		int n; cin>>n;
		vi v(n);
		FOR(o,n) cin>>v[o];
		cout << solve(n,v);
	}
}