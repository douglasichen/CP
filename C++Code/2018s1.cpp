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
	int n; cin>>n;
	vector<ll> vp(n);
	FOR(i,n) {
		cin>>vp[i];
	}
	sort(vp.begin(), vp.end());
	vector<float> rd;
	FOR(i,n-1) {
		rd.PB((float)(vp[i]+vp[i+1])/2.0);
		// cout << rd[rd.size()-1] << endl;
	}
	float minSize=1e9*2+1;
	FOR(i,rd.size()-1) {
		// cout << rd[i] << " vs " << rd[i+1] << endl;
		float size = rd[i+1] - rd[i];
		minSize = min(size,minSize);
	} 
	cout << minSize << (fmod(minSize,1)==0 ? ".0" : "") << endl;
}