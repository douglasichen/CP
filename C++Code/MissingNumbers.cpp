#include <bits/stdc++.h>
using namespace std;

bool good(int i, int j, vector<int> V, int &a, int &b) {
	int dif=V[j]-V[i];
	if (dif%2==0) {
		b = dif/2;
		a = V[j]-b;
		if (a<=0 || b<=0 || a>1e4 || b>1e4) {
			a=-1; b=-1;
			return 0;
		}
		return 1;
	}
	return 0;
}

vector<int> solve(vector<int> V) {
	int a=-1,b=-1;
	for (int i=0; i<3; i++) {
		for (int j=i+1; j<4; j++) {
			if (good(i,j,V,a,b) || good(j,i,V,a,b)) {
				// i and j and used
				vector<int> others;
				for (int o=0; o<4; o++) {
					if (o!=i && o!=j) {
						others.push_back(o);
					}
				}
				if (a*b==V[others[0]] && a/b == V[others[1]]) {
					return {a,b};
				}
				else if (a*b==V[others[1]] && a/b==V[others[0]]) {
					return {a,b};
				}
				else {
					a=-1; b=-1;
				}
			}
		}
	}
	return {a,b};	
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	vector<vector<int>> ans(T);
	for (int i=0; i<T; i++) {
		vector<int> V(4);
		for (int o=0; o<4; o++) cin>>V[o];
		ans[i]=solve(V);
	}
	for (vector<int> a : ans) cout << a[0] << ' ' << a[1] << endl; 
}