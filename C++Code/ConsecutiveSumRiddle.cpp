#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


void solve(int n) {
	int maxL = ceil(2.0/9.0 + n);
	for (int l=maxL; l>=-100; l--) {
		float p2 = sqrt(4.0/9.0 + 2*(n-l));
		float r = (2.0/3.0 + p2) * 2;
		if (l >= r || fmod(r,1)!=0) {
			r = (2.0/3.0 - p2) * 2;
			if (fmod(r,1)!=0) continue;
		}
		cout << l << ' ' << r << endl;
		break;
	}
}

int main() {
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		int t; cin>>t;
		solve(t);
	}
}