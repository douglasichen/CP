#include <bits/stdc++.h>
using namespace std;

int N,M;
unordered_map<int,vector<vector<int>>> g;

bool sorter(vector<int> a, vector<int> b) {
	return a[1]>b[1];
}

int main() {
	cin>>N>>M;

	unordered_map<int,bool> has;
	vector<int> nodes;
	for (int i=0; i<M; i++) {
		int a,b,c; cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});

		if (!has[a]) nodes.push_back(a);
		if (!has[b]) nodes.push_back(b);
		has[a]=1; has[b]=1;
	}

	for (int node : nodes) {
		sort(g[node].begin(), g[node].end(), sorter);
	}
	
	unordered_map<int,bool> isSel;
	vector<int> sels;
	sels.push_back(1);
	isSel[1]=1;
	
	long long ans=0;
	while (sels.size()<N) {
		vector<int> mCon={-1,INT_MAX};
		for (int sel : sels) {
			if (g[sel].size()==0) continue;
			vector<int> back=g[sel].back();
			while (isSel[back[0]]) {
				if (g[sel].size()==0) break;
				g[sel].pop_back();
				back=g[sel].back();
			}
			if (g[sel].size()>0) {
				if (back[1]<mCon[1]) {
					mCon=back;
					g[sel].pop_back();
				}
			}
		}
		isSel[mCon[0]]=1;
		sels.push_back(mCon[0]);
		ans+=mCon[1];
	}
	cout << ans << endl;
}