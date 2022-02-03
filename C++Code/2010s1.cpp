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

int main() {
	int n; cin>>n;
	pair<int,string> best = {0,""};
	pair<int, string> best2 = {0,""};
	for (int i=0; i<n; i++) {
		string name; cin>>name;
		int r,s,d; cin>>r>>s>>d;
		int val = 2*r + 3*s + d;
		if (val>best.F) {
			best2 = best;
			best = {val, name};
		}
		else {
			if (val>best2.F) {
				best2 = {val, name};
			}
		}
	}
	if (best.F == best2.F) {
		if (best2.S < best.S) {
			pair<int, string> temp = best2;
			best2 = best;
			best = temp;
		}
	}
	cout<<best.S<<endl;
	cout<<best2.S<<endl;
}