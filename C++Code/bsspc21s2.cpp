#include <bits/stdc++.h>
using namespace std;

long long N,K,Q;
vector<vector<long long>> O;

void solve(vector<long long> &p, vector<long long> o) {
	bool in=p[0]>=o[0] && p[0]<=o[2] && p[1]>=o[1] && p[1]<=o[3];
	if (in) {
		vector<long long> a={o[0],o[1]}, b={o[2],o[3]};
		long long s=b[0]-a[0]+1, hs=s/2;
		bool on=s%2 && (p[0]==a[0]+hs || p[1]==a[1]+hs);
		long long y=p[0],x=p[1];
		if (!on) {
			if (p[0]>=a[0]+hs && p[1]>=a[1]+hs) y=a[0]+(b[1]-p[1]), x=b[1]-(b[0]-p[0]);//, cout << "a" << endl;
			else if (p[0]>=a[0]+hs) y=b[0]-(p[1]-a[1]), x=b[1]-(b[0]-p[0]);//, cout << "b" << endl;
			else if (p[1]>=a[1]+hs) y=a[0]+(b[1]-p[1]), x=a[1]+(p[0]-a[0]);//, cout << "c" << endl;
			else y=b[0]-(p[1]-a[1]), x=a[1]+(p[0]-a[0]);//, cout << "d" << endl;
		}
		else {
			if (p[0]<a[0]+hs) y=a[0]+hs, x=a[1]+(p[0]-a[0]);
			else if (p[0]>a[0]+hs) y=a[0]+hs, x=b[1]-(b[0]-p[0]);
			else if (p[1]<a[1]+hs) y=b[0]-(p[1]-a[1]), x=a[1]+hs;
			else if (p[1]>a[1]+hs) y=a[0]+(b[1]-p[1]), x=a[1]+hs;
		}
		p={y,x};
	}
	
	// cout << p[0] << ' ' << p[1] << endl;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>K>>Q;
	O=vector<vector<long long>>(K,vector<long long>(4));
	for (int i=0; i<K; i++) cin>>O[i][0]>>O[i][1]>>O[i][2]>>O[i][3];
	reverse(O.begin(),O.end());
	vector<long long> p(2);
	for (int i=0; i<Q; i++) {
		cin>>p[0]>>p[1];
		for (vector<long long> o : O) solve(p,o);
		// cout << p[0] << ' ' << p[1] << endl;
		cout << (p[0]-1)*N+p[1] << endl;
	}
}