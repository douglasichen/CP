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
	int bw,n; cin>>bw>>n;
	vi ws(n);
	FOR(i,n) cin>>ws[i];
	
	deque<int> b;
	int ans=0;
	for (int w : ws) {
		if (b.size()==4) {
			bw+=b.back();
			b.pop_back();
			ans++;
		}
		// cout << bw << endl;
		b.push_front(w);
		bw-=w;
		if (bw<0) {
			b.pop_front();
			break;
		}
	}
	ans+=b.size();
	cout << ans << endl;
}