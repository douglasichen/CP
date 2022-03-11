#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int k) {
	vector<int> ans;
	if (n==k) {
		ans=*(new vector<int>(n));
	}
	else if (n%2==k%2) {
		for (int i=0; i<k+1; i++)
			ans.push_back(0);
		int c=1;
		for (int i=k+1; i<n; i++) {
			ans.push_back(c%2);
			c++;
		}
	}

	return ans;
}

int main() {
	int n,k; cin>>n>>k;
	vector<int> ans=solve(n,k);
	if (ans.size()==0) cout << -1 << endl;
	else {
		for (int i=0; i<n; i++) {
			cout << ans[i];
			if (i<n-1) cout << ' ';
		}
		cout << endl;
	}
}