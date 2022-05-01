#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<bool> has,inDsu;
vector<vector<int>> G;
vector<int> V,dsu;
int cmp=0;

int root(int a) {
	return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

void unite(int a, int b) {
	a=root(a); b=root(b);
	if (a==b) return;
	if (-dsu[a]>-dsu[b]) swap(a,b);
	dsu[b]+=dsu[a];
	dsu[a]=b;
	cmp--;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	freopen("closing.in","r",stdin);
	freopen("closing.out","w",stdout);

	cin>>N>>M;
	has=vector<bool>(N+1);
	inDsu=vector<bool>(N+1);
	G=vector<vector<int>>(N+1);
	V=vector<int>(N);
	dsu=vector<int>(N+1,-1);

	for (int i=0,a,b; i<M; i++) {
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i=0; i<N; i++) cin>>V[i];

	vector<bool> ans(N);
	for (int i=N-1; i>=0; i--) {
		int a=V[i];
		bool gd=0;
		for (int b : G[a]) {
			if (has[b]) {
				unite(a,b);
			}
		}
		cmp++;
		has[a]=1;
		ans[i]=cmp==1;
	}
	for (bool i : ans) cout << (i ? "YES" : "NO") << "\n";
}