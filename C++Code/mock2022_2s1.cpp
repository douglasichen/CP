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

int n, k;
void solve() {

}

int main() {
	cin>>n>>k;
	vector<string> vs(n);
	FOR(i, n) {
		cin>>vs[i];
	}
	vector<pair<int,pi>> vb(k,{{0,{0,0}},{0,{0,0}}});
	FOR(o,k) {
		FOR(i, n) {
			vb[o].F.F+=(vs[i][o]=='T');
			vb[o].S.F+=(vs[i][o]=='F');
			if (o>0) {
				vb[o].F.S.F+=(vs[i][o-1]=='T');
				vb[o].F.S.S+=(vs[i][o-1]=='F');
				vb[o].S.S.F+=(vs[i][o-1]=='T');
				vb[o].S.S.S+=(vs[i][o-1]=='F');
			}
		}
	}
	int con=10001;
	string best="";
	FOR(i,k) {
		// cout << vb[i].F << ' ' << vb[i].S << endl;
		if (vb[i].F!=0 && vb[i].F!=n){
			if (vb[i].F>vb[i].S) {
				best+='T';
			}
			else {
				if (vb[i].F==vb[i].S) {
					if (i==0) {
						best+='T';
					}
					else {
						char behind = (best.back()=='T' ? 'F' : 'T');

					}
				}
				else {
					best+='F';
				}
			}
		}
		else {
			best += (vb[i].F==n ? 'T' : 'F');
		}
	}

	for (string s : vs) {
		int com=0;
		FOR(i,s.size()) {
			if (s[i]==best[i]) com++;
		}
		if (com<con) con=com;
	}

	cout << con << endl;
}