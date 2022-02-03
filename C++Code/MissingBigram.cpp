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


string solve(int n, vector<string> v) {
	string ans="";
	ans += v[0][0];
	bool found=false;
	FOR(i,v.size()-1) {
		if (v[i][1]==v[i+1][0]) {
			ans += v[i][1];
			
		}
		else {
			ans += v[i][1];
			ans += v[i+1][0];
			found=true;
		}
	}
	
	ans += v[v.size()-1][1];
	if (!found) ans += "a";
	return ans;
}

int main() {
	int t; cin>>t;
	vector<string> vv;
	FOR(i,t) {
		int n; cin>>n;
		vector<string> v(n-2);
		FOR(o,n-2) cin>>v[o];
		vv.PB(solve(n,v));
	}
	FOR(i,t) {
		cout << vv[i] << endl;
	}
}