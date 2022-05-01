#include <bits/stdc++.h>
using namespace std;

int N,M,cnt,mxSz=1;
vector<int> dsu;

int root(int a) {
	return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

void unite(int a, int b) {
	a=root(a); b=root(b);
	if (a==b) return;
	if (-dsu[a]>-dsu[b]) swap(a,b);
	dsu[b]+=dsu[a];
	dsu[a]=b;
	cnt--;
	mxSz=max(mxSz,-dsu[b]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	cnt=N;
	dsu=vector<int>(N+1,-1);
	for (int i=0,a,b; i<M; i++) {
		cin>>a>>b;
		unite(a,b);
		cout << cnt << ' ' << mxSz << endl;
	}

}