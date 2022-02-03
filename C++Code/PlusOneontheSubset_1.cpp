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
	// int goal=0;
	// for (int i : v) goal = max(i,goal);
	unordered_map<int,bool> u;
	vi a;
	FOR(i,n) {
		if (!u[v[i]]) {
			a.PB(v[i]);
			u[v[i]]=true;
		}
	}
	sort(a.begin(), a.end());
	int ans=0;
	FOR(i,a.size()-1) {
		ans+=(a[i+1]-a[i]);
	}
	return ans;
}

int main() {
	int t; cin>>t;
	vi ans;
	FOR (i,t) {
		int n; cin>>n;
		vi v(n);
		FOR (o,n) cin>>v[o];
		ans.PB(solve(n,v));
	}
	FOR (i,t) {
		cout << ans[i] << endl;
	}
}