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


int solve(string n) {
	if ((n.back()-'0')%2==0) return 0;
	if ((n[0]-'0')%2==0) return 1;
	for (int i=1; i<n.size(); i++) if ((n[i]-'0')%2==0) return 2;
	return -1;
}

int main() {
	int t; cin>>t;
	FOR(i,t) {
		string n; cin>>n;
		cout << solve(n) << endl;
	}
}