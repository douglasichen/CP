#include <bits/stdc++.h>
using namespace std;

unordered_map<int,pair<int,int>> has;
unordered_map<int,bool> exists;

bool inRange(int n, int l, int r) {
	return n<=r && n>=l;
}

bool iHas(int n, int l, int r) {

	if (!exists[n]) return false;

	pair<int,int> nRange=has[n];
	bool ans=(inRange(nRange.first,l,r) || inRange(nRange.second,l,r) || 
	inRange(l, nRange.first, nRange.second) || inRange(r, nRange.first, nRange.second));
	// cout << "is " << n << " within range of " << l << " and " << r << "? " << (ans ? "yes" : "no") << endl;

	// cout << "n=" << n << ", nRange vs. l->r: (" << nRange.first << ',' << nRange.second << "), (" << l << "," << r << ")" << endl;  
// 
	return ans;
}

bool solve(int n, int l, int r, int x, int a[]) {
	// cout << "a: ";
	// for (int i=0; i<n; i++) cout << a[i] << ' ';
	// cout << endl;

	if (l==r) return false;

	for (int i=l-1; i<=r-1; i++) {
		int e = a[i];
		int other = x/e;
		if (e!=other) {
			if (e*other==x) {
				if (iHas(other,l-1,r-1)) {
					// cout << "com: " << e << ' ' << other << endl;
					return true;
				}
			}
		}
	}

	// unordered_map<int,int> has;
	// vector<int> v;
	// for (int i=l-1; i<=r-1; i++) {
	// 	// if (has[a[i]]==0) v.push_back(a[i]);
	// 	int e=a[i];
	// 	if (has[e]>=2) continue;
	// 	if (e<=x) {
	// 		int other=x/e;
	// 		if (has[other] && e!=other) {
	// 			if (e*other==x) {
	// 				return true;
	// 			}
	// 		}
	// 	}


	// 	has[a[i]]++;
	// }
	// for (int i=0; i<v.size(); i++) {
	// 	int e=v[i];
	// 	if (e<=x) {
	// 		int other=x/e;
	// 		if (e*other==x) {
	// 			has[e]--;
	// 			if (has[other]) {
	// 				if (e!=other) {
	// 					return true;
	// 				}
	// 			}
	// 			has[e]++;
	// 		}

	// 		// if (x%e==0) {
	// 		// 	int other=x/e;
	// 		// 	has[e]--;
	// 		// 	if (has[other] && e!=other) {
	// 		// 		// cout << "com: " << e << ' ' << other << endl;
	// 		// 		return true;
	// 		// 	}

	// 		// 	has[e]++;
	// 		// }
	// 	}
	// }
	return false;

}

int main() {
	int n,q; cin>>n>>q;
	int a[n];
	for (int i=0; i<n; i++) cin>>a[i];

	for (int i=0; i<n; i++) {
		exists[a[i]]=true;
		has[a[i]] = {-1,-1};
	}

	for (int i=0; i<n; i++) {
		if (has[a[i]].first==-1) {
			has[a[i]]={i,i};
		}
		else {
			pair<int,int> pBounds=has[a[i]];
			has[a[i]] = {min(pBounds.first, i), max(pBounds.second, i)};
		}
	}
	// for (int i=0; i<n; i++) {
	// 	cout << a[i] << ": " << has[a[i]].first << ' ' << has[a[i]].second << endl;
	// }

	vector<bool> ans(q);
	for (int i=0; i<q; i++) {
		int l,r,x; cin>>l>>r>>x;
		ans[i]=solve(n,l,r,x,a);
	}
	for (bool i : ans)
		cout << (i ? "YES" : "NO") << endl;
}