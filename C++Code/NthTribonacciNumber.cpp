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

ll tribonacci(int n) {
	if (n==0) return 0;
	if (n==1) return 1;
	if (n==2) return 1;
	if (n==3) return 2;
	deque<ll> dq;
	dq.push_back(0);
	dq.push_back(1);
	dq.push_back(1);
	dq.push_back(2);
	ll ans=2;
	int i=4;
	while (i<=n) {
		ans += ans;
		ans -= dq.front();
		// cout << "taking: " << dq.front() << endl;
		dq.push_back(ans);
		dq.pop_front();
		i++;
	}
	return ans;
}

int main() {
	int n; cin>>n;
	cout << tribonacci(n) << endl;
}