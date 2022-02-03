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
	string s; cin>>s;
	int hc=0,vc=0;
	for (char c : s) {
		if (c=='H') hc++;
		else vc++;
	}
	vi ans = {1,2,3,4};
	if (hc%2==1) {
		ans = {ans[2],ans[3],ans[0],ans[1]};
	}
	if (vc%2==1) {
		ans = {ans[1],ans[0],ans[3],ans[2]};
	}
	cout << ans[0] << ' ' << ans[1] << endl;
	cout << ans[2] << ' ' << ans[3] << endl;
}