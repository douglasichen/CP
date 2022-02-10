#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<int,vector<int>> g;

int solve(int x, int y) {
	unordered_map<int,bool> vis;
	deque<vector<int>> dq;
	vis[x]=1;
	dq.push_back({x,-1});

	while(!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		int student=back[0], dis=back[1];

		if (student==y) {
			return dis;
		}

		vector<int> friends=g[student];
		for (int f : friends) {
			if (!vis[f]) {
				dq.push_front({f,dis+1});
				vis[f]=1;
			}
		}
	}

	return -1;
}

int main() {
	cin>>n;
	for (int i=0; i<n; i++) {
		int x,y; cin>>x>>y;
		g[x].push_back(y);
	}
	int i=0;
	int x=1,y=1;
	vector<int> ans;
	while (x!=0) {
		cin>>x>>y;
		if (x==0) break;

		ans.push_back(solve(x,y));
		i++;
	}
	for (int i : ans) {
		if (i==-1) {
			cout << "No " << endl;
		}
		else {
			cout << "Yes " << i << endl;
		}
	}
}