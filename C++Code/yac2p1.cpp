#include <bits/stdc++.h>
using namespace std;

bool solve(double A, double B, double C, double D) {
	double f=B/A, g=D/C;
	if (f>g) swap(f,g);
	if (f==g) return 0;

	
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	vector<bool> ans(T);
	for (int i=0; i<T; i++) {	
		int A,B,C,D; cin>>A>>B>>C>>D;
		ans[i]=solve(A,B,C,D);
	}
	for (bool i : ans) {
		cout << (i ? "YES" : "NO") << endl;
	}
}