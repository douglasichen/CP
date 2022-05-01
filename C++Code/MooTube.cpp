#include <bits/stdc++.h>
using namespace std;

int N,Q;
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
	cin.sync_with_stdio(0);
	cin.tie(0);

	// freopen("mootube.in","r",stdin);
	// freopen("mootube.out","w",stdout);

	cin>>N>>Q;
	dsu=vector<int>(N+1,-1);
	auto cmp=[](vector<int> a, vector<int> b){return a[0]>b[0];};
	vector<vector<int>> edges(N-1);
	for (int i=0,a,b,c; i<N-1; i++) {
		cin>>a>>b>>c;
		edges[i]={c,a,b};
	}
	sort(edges.begin(),edges.end(),cmp);
	vector<vector<int>> qs(Q);
	for (int i=0,k,v; i<Q; i++) {
		cin>>k>>v;
		qs[i]={k,v,i};
	}
	sort(qs.begin(),qs.end(),cmp);

	vector<int> ans(Q);
	int pAt=0,at=0,cnt=0;
	for (vector<int> q : qs) {
		int k=q[0],v=q[1],i=q[2];
		pAt=at;
		for (; at<N-1; at++) {
			if (edges[at][0]<k) {
				at--;
				break;
			}
			else {
				unite(edges[at][1],edges[at][2]);
			}
		}
		if (at==N-1) at--;
		for (int o=pAt; o<=at; o++) {
			if (root(v)==root(edges[o][1])) cnt++;
		}
		ans[i]=cnt;
		at++;
	}

	for (int i : ans) cout << i << endl;
}