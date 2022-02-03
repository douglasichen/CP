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


vi solve(vi b) {

	for (int i=1; i<7; i++) {
		vi a = {b[0],b[i]};
		for (int o=2; o<7; o++) {
			a.PB(b[o]);
			unordered_map<ll,bool> u;
			u[a[0]+a[1]] = 1;
			u[a[0]+a[2]] = 1;
			u[a[1]+a[2]] = 1;
			u[a[0]+a[1]+a[2]] = 1;

			int ok=1;
			FOR(j,7) {
				if (j!=0&&j!=i&&j!=o) {
					if (u[b[j]]==0) {
						ok=0;
						break;
					}
					// cout << b[j] << " is good" << endl;
				}
			}
			if (ok) return a;
			a.pop_back();
		}
	}	
	return {-1,-1,-1};
}

int main() {
	int t; cin>>t;
	vector<vi> vv;
	FOR(i,t) {
		vi v(7);
		FOR(o,7) cin>>v[o];
		vi ans = solve(v);
		vv.PB(ans);
		
	}
	for (vi v : vv) {
		FOR(i,3) cout<<v[i]<<' ';
		cout << endl;
	}
}