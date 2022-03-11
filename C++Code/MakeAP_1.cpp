#include <bits/stdc++.h>
using namespace std;

bool solve(int a, int b, int c) {
	// for a:
	int nA=b+(b-c);
	if (nA>0 && nA%a==0) {
		// cout << "A" << endl;
		return 1;
	}

	int nB=(a+c)/2;
	if ((a+c)%2==0 && nB%b==0) {
		// cout << "B" << endl;
		return 1;
	}

	int nC=b+(b-a);
	if (nC>0 && nC%c==0) {
		// cout << "C" << endl;
		return 1;
	}

	return 0; // nothing works
}

int main() {
	int t; cin>>t;
	bool ans[t];
	for (int i=0; i<t; i++) {
		int a,b,c; cin>>a>>b>>c;
		ans[i]=solve(a,b,c);
	}	
	for (bool i : ans) {
		cout << (i ? "YES" : "NO") << endl;
	}
}
