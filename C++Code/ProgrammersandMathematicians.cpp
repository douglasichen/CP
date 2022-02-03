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


int solve(int a, int b) {
	// if (a+b<4) return 0;
	// if (a==0||b==0) return 0;
	// int temp = a;
	// if (a>b) {
	// 	a = b;
	// 	b = temp;
	// }
	// // cout << "checking: " << a << ' ' << b << endl;
	// int ones = b/3;
	// int ans1=min(a,ones);

	// int twos = b/2;
	// int ans2=min(a/2,twos);
	// int ans = max(ans1,ans2);
	// if (ans2 >= ans1) {
	// 	a -= ans2*2;
	// 	b -= ans2*2;
	// 	if (a+b>=4) ans++;
	// }
	// // cout << a << ' ' << b << endl;
	// // cout << ans1 << ' ' << ans2 << endl;
	
	if (a>b) swap(a,b);
	int maxTriplets = b/3;
	int maxDoubles = b/2;

	int singlesAns = min(a,maxTriplets);
	int doubleAns = min(a/2, maxDoubles);

	doubleAns += singleExtra;


	return ans;
}

int main() {
	int t; cin>>t;
	vi v;
	FOR(i,t) {
		int a,b; cin>>a>>b;
		v.PB(solve(a,b));
	}
	for (int i : v) cout << i << endl;
}