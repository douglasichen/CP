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
	int a=0,b=0,c=0;
	for (char ch : s) {
		if (ch=='A') a++;
		else if (ch=='B') b++;
		else c++;
	}
	// cout << a << ' ' << b << ' ' << c << endl;
	if (b==0) return false;
	if (a>0) {
		int ab = (c==0 ? max(a,b) : a);
		a -= ab;
		b -= ab;
	}
	if (c>0) {
		int bc = max(b,c);
		b -= bc;
		c -= bc;
	}
	// cout << a << ' ' << b << ' ' << c << endl;
	if (a==0 && b==0 && c==0) return true;
	return false;
}

int main() {
	int n; cin>>n;
	vector<bool> v;
	FOR(i,n) {
		string s; cin>>s;
		v.PB(solve(s));
	}
	for (bool b : v) {
		cout << (b ? "YES" : "NO") << endl;
	}
}