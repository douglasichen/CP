#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> v) {
	int ans=0;
	int state=0;
	int k=0;
	for (int i=1; i<n; i++) {
		int dif = v[i] - v[i-1];
		dif = max(-1,dif);
		dif = min(1,dif);
		// cout << dif << ' ';
		// cout << "state: " << state << endl;
		// cout << v[i] << ' ';
		k++;
		if (state==0) {
			if (dif<0) {
				// cout << "decreasing...";
			}
			else if (dif==0) {
				// cout << "the same...";
				state=1;
			}
			else {
				// cout << "increasing..." ;
				state=2;
			}
		}
		else if (state==1) {
			if (dif>0) {
				// cout << "increasing...";
				state=2;
			}
			else if (dif<0) {
				// cout << "restart...";
				k=0;
				state=0;
			}
		}
		else {
			if (dif<=0) {
				// cout << "end... with k=" << k ;
				// cout << k << ' ';
				ans = max(k,ans);
				state=0;
				k=0;
				i--;
			}
		}
		// cout << endl;
		if (state==2) {
			if (i==n-1) {
				// cout << "end... with k=" << k ;
				ans = max(k,ans);
			}
		}
	}
	// cout << endl;
	return ans;
}

int main() {
	int n; cin>>n;
	vector<int> v(n);
	for (int i=0; i<n; i++) cin>>v[i];
	cout << solve(n,v) << endl;
}