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

int solve(vi v) {
	
	int biggest = 0;
	vi pastVv;
	vi vv;
	while (true) {
		vv.clear();
		FOR(i,v.size()-1) {
			int k = v[i];
			if (i<v.size()-2) {
				if (v[i]==v[i+2]) {
					k*=2;
					k+=v[i+1];
					
					// cout << "combining: ";
					// for (int o=i; o<=i+2; o++) cout << v[o] << ' ';
					// cout << endl;
					i+=2;
				}
				else if (v[i]==v[i+1]) {
					k*=2;
					
					// cout << "combining: ";
					// for (int o=i; o<=i+1; o++) cout << v[o] << ' ';
					// cout << endl;
					i+=1;
				}
			}
			else if (v[i]==v[i+1]) {
				k*=2;
				
				// cout << "combining: ";
				// for (int o=i; o<=i+1; o++) cout << v[o] << ' ';
				// cout << endl;
				i+=1;
			}
			if (k>biggest) biggest=k;
			vv.PB(k);
			
		}
		
		vv.PB(v[v.size()-1]);
		if (vv==pastVv) break;
		pastVv = vv;
		v = vv;
		// for (int i : vv) cout << i << ' ';
		// cout << endl;
	}
	sort(vv.begin(), vv.end(), greater<int>());

	return vv[0];
}

int solve2(vi v) {
	
	int biggest = 0;
	vi pastVv;
	vi vv;
	while (true) {
		vv.clear();
		FOR(i,v.size()-1) {
			int k = v[i];

			if (v[i]==v[i+1]) {
				k*=2;
				i+=1;
			}
			else if (i<v.size()-2) {
				if (v[i]==v[i+2]) {
					k*=2;
					k+=v[i+1];
					i+=2;
				}
			}
			if (k>biggest) biggest=k;
			vv.PB(k);
		}
		
		vv.PB(v[v.size()-1]);
		if (vv==pastVv) break;
		pastVv = vv;
		v = vv;
	}
	sort(vv.begin(), vv.end(), greater<int>());

	return vv[0];
}



int main() {
	int n; cin>>n;
	vi v(n);
	
	FOR(i,n) cin>>v[i];

	int g = solve(v);
	int f = solve2(v);
	if (f > g) g = f;
	cout << g << endl;
}