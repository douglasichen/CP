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


string solve(string s) {
	sort(s.begin(), s.end());
	return s;
}

int main() {
	int t; cin>>t;
	vector<string> v;
	FOR(i,t) {
		string s; cin>>s;
		v.PB(solve(s));
	}
	for (string s : v) {
		cout << s << endl;
	}
}