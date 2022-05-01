#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	vector<int> V(N),locs(1e5+1,-1);
	vector<vector<int>> Qs(Q,vector<int>(4));
	for (int i=0; i<N; i++) cin>>V[i];
	for (int i=0; i<Q; i++) Qs[i][0]=i, cin>>Qs[i][1]>>Qs[i][2]>>Qs[i][3];
	auto cmp=[](vector<int> a, vector<int> b){return a[2]<b[2];};
	sort(Qs.begin(),Qs.end(),cmp);
	vector<bool> A(Q);
	int i=0;
	for (vector<int> q : Qs) {
		int L=q[1]-1,R=q[2]-1,X=q[3];
		while (i<=R) locs[V[i]]=i, i++;
		bool ans=0;
		for (int a=1; a*a<X; a++) {
			if (X%a==0) {
				int b=X/a;
				if (locs[a]>=L && locs[b]>=L) {
					ans=1;
					break;
				}
			}
		}
		A[q[0]]=ans;
	}
	for (bool i : A) cout << (i ? "YES" : "NO") << endl;
}