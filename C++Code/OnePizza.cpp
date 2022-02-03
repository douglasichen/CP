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


void solve() {

}

int main() {
	unordered_map<string,pi> t;
	int n; cin>>n;
	vector<pair<vector<string>,vector<string>>> v;
	FOR(i,n) {
		int l; cin>>l;
		vector<string> lv(l);
		FOR(o,l) cin>>lv[o];

		int d; cin>>d;
		vector<string> dv(d);
		FOR (o,d) cin>>dv[o];

		v.PB({lv,dv});
	}

	vector<string> check;
	FOR(i,n) {
		vector<string> like = v[i].F, dislike = v[i].S;
		for (string s : like) {
			t[s].F++;
			if (!t[s].S) {
				t[s].S = 1;
				check.PB(s);
			}
		}
		for (string s : dislike) {
			t[s].F--;
			if (!t[s].S) {
				t[s].S=1;
				check.PB(s);
			}
		}
	}
	
	int cnt=0;
	vector<string> ans;
	for (string s : check) {
		if (t[s].F>0) {
			cnt++;
			ans.PB(s);
		}
	}
	cout << ans.size() << ' ';
	for (string s : ans) cout << s << ' ';
	cout<<endl;
}