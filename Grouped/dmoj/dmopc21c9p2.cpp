#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

bool solve(string &A, string &B) {
	int aN=A.size(), bN=B.size();
	string sA="";
	for (int b=0, a=0; b<bN; b++, a++) {
		if (A[a]!=B[b]) {
			if (A[a]=='b' || a==aN-1) break;
			if (A[a]==A[a+1]) a++, sA+='b';
			// else return 0;
		}
		else sA+=A[a];
	}
	// cout << sA << " " << B << endl;
	return sA==B;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		string A,B; cin>>A>>B;
		cout << (solve(A,B) ? "YES" : "NO") << endl;
	}
}