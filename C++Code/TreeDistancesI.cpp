#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;


void bfs(int start, vector<int> &dists) {
	deque<vector<int>> dq; // node, behind, dis;
	dq.push_back({start,0,0});
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		dists[back[0]]=back[2];
		for (int i : G[back[0]]) {
			if (i!=back[1]) {
				dq.push_front({i,back[0],back[2]+1});
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	G=vector<vector<int>>(N+1);
	for (int i=0,a,b; i<N-1; i++) {
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> inds(N+1),dists(N+1);
	for (int i=1; i<=N; i++) inds[i]=i;
	bfs(1,dists);
	auto cmp=[&](int &a, int &b) {return dists[a]>dists[b];};
	sort(inds.begin(),inds.end(),cmp);
	for (int i=1,ans; i<=N; i++) {
		if (i==inds[0]) ans=dists[i]+dists[inds[1]];
		else ans=dists[i]+dists[0];
		cout << ans << ' ';
	}
	cout << endl;
}