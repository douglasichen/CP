#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


void solve() {

}

void printPi(pi p) {
	cout<<p.F<<' '<<p.S<<endl;
}

void printPv(vector<pi> vp) {
	for (int i=0; i<vp.size(); i++) printPi(vp[i]);
	cout<<endl;
}

bool sorter(pi a, pi b) {
	if (a.S==b.S) return a.F > b.F;
	return a.S > b.S;
}

int main() {
	vi map(1002);
	vi ind;
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		int inp; cin>>inp;
		if (map[inp]==0) ind.PB(inp);
		map[inp]++;
	}
	vector<pi> pv;
	for (int i=0; i<ind.size(); i++) {
		int index = ind[i];
		pv.PB({index, map[index]});
	}
	// printPv(pv);
	sort(pv.begin(), pv.end(), sorter);
	// printPv(pv);

	int f1=pv[0].S;
	int f2=f1;
	for (int i=1; i<pv.size(); i++) {
		if (pv[i].S<f1) {
			f2 = pv[i].S;
			break;
		}
	}
	vi v1,v2;
	for (int i=0; i<pv.size(); i++) {
		if (pv[i].S!=f1 && pv[i].S!=f2) break;
		if (pv[i].S==f1) v1.PB(pv[i].F);
		if (pv[i].S==f2) v2.PB(pv[i].F);
	}
	if (v1.size()>=2) {
		cout<< abs(v1[0]-v1[v1.size()-1]) << endl;
	}
	else {
		int ans1 = abs(v1[0]-v2[v2.size()-1]);
		int ans2 = abs(v1[v1.size()-1]-v2[0]);
		cout << max(ans1, ans2) << endl;
	}
	// solve();
}