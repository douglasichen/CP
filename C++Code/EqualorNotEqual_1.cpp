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


bool solve(string s) {
	int cnt=0;
	for (char c : s) {
		if (c=='N') cnt++;
		if (cnt==2) return true;
	}
	if (cnt==0) return true;
	return false;
}

int main() {
	int t; cin>>t;
	vector<bool> ans;
	FOR(i,t) {
		string s; cin>>s;
		ans.PB(solve(s));
	}
	for (bool i : ans) {
		cout << (i ? "YES" : "NO") << endl;
	}
}