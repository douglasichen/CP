#include <bits/stdc++.h>
using namespace std;

int N,Q;
vector<int> V;
vector<vector<int>> F;


bool inBounds(int i, int L, int R) {
	return i>=L && i<=R;
}

int has(int e, int L, int R) {
	// just find if the bounds include the left then check 1 to the right to see if it is not single
	vector<int> ats=F[e];
	int sz=ats.size();
	if (sz==0) return -1;

	int left=0, right=sz-1;
	while (left<right) {
		int mid=(left+right)/2;
		if (ats[mid]<L) {
			left=mid+1;
		}
		else if (ats[mid]>R) {
			right=mid-1;
		}
		else {
			left=mid;
			break;
		};
	}
	if (inBounds(ats[left],L,R)) {
		return ats[left];
	}
	return -1;
}

bool solve(int L, int R, int X) {
	int mxI=sqrt(X);
	for (int i=1; i<=mxI; i++) {
		if (X%i==0) {
			int a=i, b=X/i;
			if (a==b) break;
			int resA=has(a,L,R), resB=has(b,L,R);
			// cout << "Res: " << resA << ' ' << resB << endl;
			if (resA!=-1 && resB!=-1) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>Q;
	V=vector<int>(N);
	F=vector<vector<int>>(1e5+1);
	for (int i=0; i<N; i++) {
		cin>>V[i];
		F[V[i]].push_back(i);
	}
	
	vector<bool> ans(Q);
	for (int i=0; i<Q; i++) {
		int L,R,X; cin>>L>>R>>X;
		L--; R--;
		bool b=1;
		// cout << has(X,L,R,b) << endl;
		ans[i]=solve(L,R,X);
	}
	for (bool i : ans) cout << (i ? "YES" : "NO") << endl;
}