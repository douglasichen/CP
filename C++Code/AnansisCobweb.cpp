#include <bits/stdc++.h>
using namespace std;

int N,M,Q;
vector<int> dsu;
int cnt=0;

int root(int a) {
	return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

void unite(int a, int b) {
	a=root(a); b=root(b);
	if (a==b) return;
	cnt--;
	if (-dsu[a]>-dsu[b]) swap(a,b);
	dsu[b]+=dsu[a];
	dsu[a]=b;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	cnt=N;
	dsu=vector<int>(N+1,-1);
	vector<vector<int>> edges(M+1);
	for (int i=1,a,b; i<=M; i++) {
		cin>>a>>b;
		edges[i]={a,b};
	}
	cin>>Q;
	vector<bool> have(M+1,1);
	vector<int> rem(M+1);
	for (int i=1,inp; i<=Q; i++) {
		cin>>inp;
		rem[i]=inp;
		have[inp]=0;
	}
	for (int i=1; i<=M; i++) {
		if (have[i]) unite(edges[i][0],edges[i][1]);
	}
	int ans[Q+1];
	for (int i=Q; i>0; i--) {
		ans[i]=cnt;
		vector<int> edge=edges[rem[i]];
		unite(edge[0],edge[1]);
	}
	for (int i=1; i<=Q; i++) cout << ans[i] << ' ';
	cout << endl;
}