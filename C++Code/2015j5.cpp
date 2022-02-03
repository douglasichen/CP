#include <bits/stdc++.h>
using namespace std;

int solve(int p, int k) {
	int ans=0;
	int start = ceil((float)p/(float)k);
	vector<int> v(k, start);
	int r = p%k;
	for (int i=0; i<r; i++) v[i]--;

	for (int i=0; i<k-1; i++) {
		int add = v[i]-1;
		v[k-1]+=add;
	}


	return ans;
}

int main() {
	int p,k; cin>>p>>k;
	cout << solve(p,k) << endl;
}