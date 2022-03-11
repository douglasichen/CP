#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int a, int b) {

	vector<int> v(n);
	int bound=n/2, left=bound-1, right=bound;
	v[left]=a; v[right]=b;
	left--; right++;

	// edge case
	if (n==2) return v;
	
	unordered_map<int,bool> has;
	for (int i=a-1; i>=1; i--) {
		if (right>=n) return {-1};
		if (i==b || has[i]) continue;
		if (i<b) {
			v[right]=i;
			right++;
			has[i]=1;
		}
		else return {-1};
	}
	for (int i=b+1; i<=n; i++) {
		if (left<0) return {-1};
		if (i==a || has[i]) continue;
		if (i>a) {
			v[left]=i;
			left--;
			has[i]=1;
		}
		else return {-1};
	}

	for (int i=1; i<=n; i++) {
		if (!has[i] && i!=a && i!=b) {
			if (i>a && i<b) {
				int lSpace=left, rSpace=n-right-1;
				if (lSpace>rSpace) {
					if (left<0) return {-1};
					v[left]=i;
					left--;
				}
				else {
					if (right>=n) return {-1};
					v[right]=i;
					right++;
				}
			}
			else if (i>a) {
				if (left<0) return {-1};
				v[left]=i;
				left--;
			}
			else if (i<b) {
				if (right>=n) return {-1};
				v[right]=i;
				right++;
			}
			else return {-1};
		}
	}

	
	return v;
}

int main() {
	int t; cin>>t;
	vector<int> ans[t];
	for (int i=0; i<t; i++) {
		int n,a,b; cin>>n>>a>>b;
		ans[i]=solve(n,a,b);
	}

	for (vector<int> i : ans) {
		for (int e : i) cout << e << ' ';
		cout << endl;
	}
}