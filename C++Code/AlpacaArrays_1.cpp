#include <bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> has;
unordered_map<int,bool> exists;

int a[1000001];

bool inRange(int n, int l, int r) {
	return n>=l && n<=r;
}

bool solve(int n, int l, int r, int x) {

	for (int i=l-1; i<=r-1; i++) {
		int e=a[i];
		int other = x/e;
		if (exists[other] && e!=other && e*other==x) {
			for (int k : has[other]) {
				if (inRange(k,l-1,r-1))
					return true;
			}
		}
	}

	return false;
}

int main() {
	int n,q; cin>>n>>q;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		exists[a[i]]=true;
		has[a[i]].push_back(i);
	}



	// for (int i=0; i<n; i++) {
	// 	cout << a[i] << ": " << has[a[i]].first << ' ' << has[a[i]].second << endl;
	// }

	vector<bool> ans(q);
	for (int i=0; i<q; i++) {
		int l,r,x; cin>>l>>r>>x;
		ans[i]=solve(n,l,r,x);
	}
	for (bool i : ans)
		cout << (i ? "YES" : "NO") << endl;
}