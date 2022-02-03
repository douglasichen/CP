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


vector<vector<char>> solve(int n, int k) {
	vector<vector<char>> ans(n,*(new vector<char>(n,'.')));
	int a=0;
	for (int i=0; i<n; i+=2) {
		ans[i][i]='R';
		a++;
		if (a==k) break;
	}
	if (a<k) ans = {{'-','1'}};
	return ans;
}

int main() {
	int t; cin>>t;
	vector<vector<vector<char>>> ans;
	FOR(i,t) {
		int n,k; cin>>n>>k;
		ans.PB(solve(n,k));
	}
	for (vector<vector<char>> a : ans) {
		for (vector<char> vc : a) {
			for (char c : vc) {
				cout << c;
			}
			cout << endl;
		}
	}
}