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


int solve(int n) {
	string s = to_string(n);
	unordered_map<char,bool> u;
	for (char c : s) {
		if (u[c]) return false;
		u[c]=true;
	}
	return true;
}

int main() {
	int n; cin>>n;
	n++;
	while (!solve(n)) {
		n++;
	}
	cout << n << endl;
}