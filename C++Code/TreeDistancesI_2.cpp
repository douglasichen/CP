#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;
vector<int> dists;
vector<int> frm;
vector<bool> vis;

void trav(int start) {
	deque<vector<int>> dq; // node, behind
	dq.push_back({start,0});
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		for (int i : G[back[0]]) {
			if (i!=back[1]) {
				dq.push_back({i,back[0]});
				dists[i]=dists[back[0]]+1;
				frm[i]=back[0];
			}
		}
	}
}

int root(int start) {
	vis[start]=1;
	while (frm[start]!=0) {
		start=frm[start];
		if (vis[start]) break;
		vis[start]=1;
	}
	return start;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	G=vector<vector<int>>(N+1);
	dists=vector<int>(N+1);
	frm=vector<int>(N+1);
	vis=vector<bool>(N+1);
	for (int i=0,a,b; i<N-1; i++) {
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	trav(1);
	

}