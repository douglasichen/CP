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
	int j; cin>>j;
	int a; cin>>a;
	vi jv,av(j,6);
	for (int i=0; i<j; i++) {
		char c; cin>>c;
		int size=1;
		if (c=='M') size=2;
		if (c=='L') size=3;
		jv.PB(size);
	}
	for (int i=0; i<a; i++) {
		char c; cin>>c;
		int jn; cin>>jn; jn-=1;
		int size=1;
		if (c=='M') size=2;
		if (c=='L') size=3;
		if (size<av[jn]) {
			av[jn]=size;
		}
	}
	int cnt=0;
	for (int i=0; i<j; i++) {
		if (av[i] <= jv[i]) {
			cnt++;
		}
	}
	cout<<cnt<<endl;

	// solve();
}