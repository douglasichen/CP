#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> dists;
vector<vector<int>> G;

// return a far node
int bfs(int start) {
	vector<bool> vis(N+1);
	deque<vector<int>> dq; // node, dis
	vis[start]=1; dq.push_back({start,0});
	vector<int> far={0,0};
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		dists[back[0]]=max(dists[back[0]],back[1]);
		if (back[1]>far[1]) far=back;
		for (int i : G[back[0]]) {
			if (!vis[i]) {
				vis[i]=1;
				dq.push_front({i,back[1]+1});
			}
		}
	}
	return far[0];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	dists=vector<int>(N+1);
	G=vector<vector<int>>(N+1);
	for (int i=0,a,b; i<N-1; i++) {
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bfs(bfs(bfs(1)));
	for (int i=1; i<=N; i++) cout << dists[i] << ' ';
	cout << endl;
}