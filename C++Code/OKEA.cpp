#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k) {
	bool ok=0;
	int nums=n*k;
	if (nums%2==0) {
		if (nums/2 % k==0) {
			ok=1;
		}
	}
	if (k==1) ok=1;
	if (ok) {
		vector<vector<int>> ans(n,*(new vector<int>(k)));
		deque<int> odds,even;
		for (int i=1; i<=n*k; i++) {
			if (i%2==0) even.push_back(i);
			else odds.push_back(i);
		}
		for (int y=0; y<n; y++) {
			for (int x=0; x<k; x++) {
				if (!odds.empty()) {
					ans[y][x]=odds.front();
					odds.pop_front();
				}
				else {
					ans[y][x]=even.front();
					even.pop_front();
				}
			}
		}
		cout << "YES" << endl;
		for (int y=0; y<n; y++) {
			for (int x=0; x<k; x++) {
				cout << ans[y][x] << ' ';
			}
			cout << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}

}

int main() {
	int t; cin>>t;
	vector<vector<int>> inp(t,*(new vector<int>(2)));
	for (int i=0; i<t; i++) {
		cin>>inp[i][0]>>inp[i][1];
	}
	for (int i=0; i<t; i++) {
		solve(inp[i][0],inp[i][1]);
	}
}