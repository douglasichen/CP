#include <bits/stdc++.h>
using namespace std;

int N,Q;
vector<int> V;
vector<vector<int>> Rs;


void add(int L, int R) {
	for (int i=L; i<R; i++) {
		if (V[i]==0) {
			V[i]=V[i-1]+1;
		}
	}
	if (V[R]==0)
		V[R]=min(V[R-1]+1,V[L-1]);
}

bool sorter(vector<int> a, vector<int> b) {
	int szA=a[1]-a[0]+1, szB=b[1]-b[0]+1;
	return szA>szB;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>Q;
	if (Q==0) {
		cout << 1 << endl;
		for (int i=0; i<N; i++) {
			cout << 1;
			if (i<N-1) cout << ' ';
		}
		cout << endl;
		return 0;
	}
	
	V=vector<int>(N+1);
	Rs=vector<vector<int>>(Q);
	V[0]=INT_MAX;
	V[1]=1;
	for (int i=0; i<Q; i++) {
		int L,R; cin>>L>>R;
		Rs[i]={L,R};
	}
	sort(Rs.begin(), Rs.end(), sorter);
	for (vector<int> r : Rs) {
		cout << r[0] << " vs " << r[1] << endl;
		add(r[0],r[1]);
	}
	
	int dif=0;
	for (int i=1; i<=N; i++) dif=max(dif,V[i]);
	
	cout << dif << endl;
	for (int i=1; i<=N; i++) {
		cout << V[i];
		if (i<N) cout << " ";
	}
	cout << endl;
	
}