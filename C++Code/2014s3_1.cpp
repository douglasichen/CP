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


bool solve(int n, stack<int> main) {
	stack<int> side;
	int i=1;
	while (!main.empty() || !side.empty()) {
		int topMain = (main.empty() ? -1 : main.top());
		int topSide = (side.empty() ? -1 : side.top());
		if (topMain==i) {
			main.pop();
			i++;
			// cout << "left main: " << topMain << endl;
		}
		else if (topSide==i) {
			side.pop();
			i++;
			// cout << "left side: " << topSide << endl; 
		}
		else {
			side.push(topMain);
			main.pop();
			// cout << "main to side: " << topMain << endl;
		}
		if (main.empty() && side.empty()) return true;
		if (main.empty() && i!=side.top()) return false;
	}
	return true;
}

int main() {
	int t; cin>>t;
	vector<bool> ans;
	FOR(i,t) {
		int n; cin>>n;
		stack<int> s;
		FOR(o,n) {
			int inp; cin>>inp;
			s.push(inp);
		}
		ans.PB(solve(n,s));
 	}
	
	for (bool a : ans) cout << (a ? "Y" : "N") << endl;
}