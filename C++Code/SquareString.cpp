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
	if (s.size()%2!=0) return false;
	return s.substr(0,s.size()/2) == s.substr(s.size()/2);
}

int main() {
	int t; cin>>t;
	FOR(i,t) {
		string s; cin>>s;
		cout << (solve(s) ? "YES" : "NO") << endl;
	}
}