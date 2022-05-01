#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;

vector<int> bfs(int start) {
	vector<int> ans(2);
	deque<vector<int>> dq; //node, behind, dis
	dq.push_back({start,0,0});
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		if (back[2]>ans[1]) ans={back[0],back[2]};
		for (int i : G[back[0]]) {
			if (i!=back[1]) {
				dq.push_front({i,back[0],back[2]+1});
			}
		}
	}
	return ans;
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
	vector<int> ans=bfs(1);
	ans=bfs(ans[0]);
	cout << ans[1] << endl;
}