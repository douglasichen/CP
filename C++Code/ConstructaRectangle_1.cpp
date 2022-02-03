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


bool solve(vi v) {
	sort(v.begin(), v.end());
	int dif=-1;
	if (v[0]==v[1]) dif = v[2];
	else if (v[0]==v[2]) dif = v[1];
	else if (v[1]==v[2]) dif = v[0];
	if (dif==-1) {
		return (v[2]==v[0]+v[1]);
	}
	else {
		return dif%2==0;
	}
}

int main() {
	int t; cin>>t;
	vector<bool> ans;
	FOR(i,t) {
		vi v(3); cin>>v[0]>>v[1]>>v[2];
		ans.PB(solve(v));
	}
	for (bool i : ans){
		cout << (i ? "YES" : "NO") << endl;
	}
}