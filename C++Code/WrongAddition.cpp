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


string solve(string a, string s) {
	if (s.size()<a.size()) return "-1";
	ll sLoc=s.size()-1;
	string b="";
	deque<string> dq;
	for (int i=a.size()-1; i>=0; --i) {
		int ai = a[i]-'0';
		int si = s[sLoc] - '0';
		if (ai >= si) {
			if (sLoc-1<0) return "-1";
			string p="";
			p += s[sLoc-1];
			p += s[sLoc];
			// cout << "p: " << p << endl;
			si = stoi(p);
			sLoc--;
			// cout << "doing the double" << endl;
			// si = stoi(s[sLoc-1] + s[sLoc]);
		}
		cout << si << endl;
		dq.push_front(to_string(si-ai));
		sLoc--;
	}
	string rb="";
	bool lead0=true;
	while (!dq.empty()) {
		string back = dq.front();
		dq.pop_front();
		if (back=="0") {
			if (lead0) continue;
		}
		else {
			lead0=false;
		}
		rb+=back;
	}
	return rb;
}

int main() {
	int t; cin>>t;
	vector<string> v;
	FOR(i,t) {
		string a,s; cin>>a>>s;
		// cout << solve(a,s) << endl;
		// v.PB(solve(a,s));
	}
	FOR(i,t) {
		cout << v[i] << endl;
	}
}