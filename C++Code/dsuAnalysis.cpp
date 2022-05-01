#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) {
		return e[x]<0 ? x : e[x]=get(e[x]);
	}

	int size(int x) {
		return -e[get(x)];
	}

	bool unite(int x, int y) {  // union by size
		x=get(x), y=get(y);
		if (x==y) return false;
		if (e[x]>e[y]) swap(x, y);
		e[x]+=e[y]; e[y]=x;
		return true;
	}
};


// only roots are negative, positive branch to a root

int N,M;
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
}

int main() {
	cin>>N>>M;
	dsu=vector<int>(N+1,-1);
	for (int i=0,a,b; i<M; i++) {
		cin>>a>>b;
		unite(a,b);
	}
	bool ans=root(1)==root(4);
	cout << ans << endl;

}