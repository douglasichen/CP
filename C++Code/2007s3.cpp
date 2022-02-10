#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g(10000);

int bfs(int a, int b) {
	vector<bool> vis(10000);
	vis[a]=true;
	deque<vector<int>> dq;
	dq.push_back({a,0});

	while(!dq.empty()) {
		vector<int> back=dq.back();
		dq.pop_back();
		if (back[0]==b) return back[1];
		
		for (int i : g[back[0]]) {
			if (!vis[i]) {
				dq.push_front({i,back[1]+1});
				vis[i]=true;
			}
		}
	}
	return -1;
}

int solve(int x, int y) {
	int x2y=bfs(x,y), y2x=bfs(y,x);
	
	if (x2y==-1 || y2x==-1) return -1;

	int ans=x2y-1;
	return ans;
}

int main() {
	cin>>n;
	for (int i=0; i<n; i++) {
		int a,b; cin>>a>>b;
		g[a].push_back(b);
	}
	
	vector<int> ans;
	while (true) {
		int x,y; cin>>x>>y;
		if (x==0&&y==0) break;
		ans.push_back(solve(x,y));
	}
	for (int i : ans) {
		if (i==-1) cout << "No" << endl;
		else {
			cout << "Yes " << i << endl;
		}
	}
}