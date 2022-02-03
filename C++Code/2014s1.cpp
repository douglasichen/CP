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
	int n, m; cin>>n>>m;
	vi rem(m), f(n+1);
	FOR(i,m) cin>>rem[i];
	FOR(i,n+1) f[i]=i;
	
	vi ans=f;
	for (int r : rem) {
		vi nAns={ans[0]};
		for (int i=1; i<ans.size(); i++)
			if (i%r!=0)
				nAns.PB(ans[i]);
		ans = nAns;
	}
	for (int i=1; i<ans.size(); i++ ){
		cout << ans[i] << endl;
	}
}