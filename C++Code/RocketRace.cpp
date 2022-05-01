#include <bits/stdc++.h>
using namespace std;

int N,Q;
vector<vector<int>> V,orig;


bool sorter(vector<int> a, vector<int> b) {
	return a[0]>b[0];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	V=vector<vector<int>>(N,vector<int>(2));
	for (int i=0; i<N; i++) {
		int a,b; cin>>a>>b;
		int val=a-b;
		V[i][0]=val;
		V[i][1]=i;
	}
	// for (vector<int> i : V) cout << i[0] << ' ';
	// cout << endl;
	orig=V;
	sort(V.begin(), V.end(), sorter);

	cin>>Q;
	vector<int> ans;
	for (int i=0; i<Q; i++) {
		int j; cin>>j;
		if (j==0) {
			int k; cin>>k;
			long long sm=0;
			int rc=0;
			for (int o=0; o<N; o++) {
				if (V[o][0]<=0) break;
				rc++;
				int ind=V[o][1];
				if (sm+orig[ind][0]>=k) {
					sm+=orig[ind][0];
					break;
				}
				else {
					sm+=V[o][0];
				}
				
			}
			if (sm>=k) {
				ans.push_back(rc);
			}
			else {
				ans.push_back(-1);
			}
		}
		else {
			int x,y; cin>>x>>y;

		}
	}
	for (int i : ans) cout << i << endl;
	 
}