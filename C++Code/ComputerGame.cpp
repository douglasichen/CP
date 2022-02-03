#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


void solve(int n, vector<vi> v) {
	for (int i=0; i<n; i++) {
		if (v[0][i]+v[1][i]==2) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main() {
	int t; cin>>t;
	for (int i=0; i<t; i++) {
		int n; cin>>n;
		vector<vi> v(2,*(new vi(n)));
		
		for (int o=0; o<2; o++) {
			for (int p=0; p<n; p++) {
				char c; cin>>c; c-='0';
				v[o][p] = c;
			}
		}
		solve(n,v);
	}
}