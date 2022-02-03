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

// floats and double always should be set precision to high number setprecision(100);
void solve() {

}

int main() {
	int n; cin>>n;
	vi ed(n+1), w(n);
	FOR(i,n+1) cin>>ed[i];
	FOR(i,n) cin>>w[i];
	
	double area=0;
	FOR(i,n) {
		// area += min(ed[i],ed[i+1]) * w[i] + (max(ed[i],ed[i+1]) - min(ed[i],ed[i+1])) * w[i] / 2.0;
		area += w[i] * (ed[i]+ed[i+1]) / 2.0;
	}
	cout << setprecision(100) << area << endl;
}