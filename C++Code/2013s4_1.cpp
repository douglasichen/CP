#include <bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> t;

bool foundGoal(int a, int b) {
	unordered_map<int,bool> vis;
	deque<int> dq; dq.push_back(a);
	vis[a]=1;

	while (!dq.empty()) {
		int back=dq.back();
		dq.pop_back();

		if (back==b) {
			return 1;
		}

		vector<int> nexts=t[back];
		for (int next : nexts) {
			if (!vis[next]) {
				dq.push_front(next);
				vis[next]=1;
			}
		}
	}
	return 0;
}

int main() {
	
	int n,m; cin>>n>>m;
	for (int i=0; i<m; i++) {
		int x,y; cin>>x>>y;
		t[x].push_back(y);
	}
	
	int p,q; cin>>p>>q;
	
	if (foundGoal(p,q)) {
		cout << "yes" << endl;
	}
	else if (foundGoal(q,p)) {
		cout << "no" << endl;
	}
	else {
		cout << "unknown" << endl;
	}	
}