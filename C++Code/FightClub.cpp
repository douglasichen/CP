#include <bits/stdc++.h>
using namespace std;

bool works(unordered_map<int,vector<int>> g, int boss) {
	unordered_map<int,bool> vis;
	vis[boss]=true;
	queue<int> q;
	q.push(boss);

	while (!q.empty()) {
		int back=q.back();
		q.pop();
		
		for (int i : g[back]) {
			if (vis[i]) return false;
			
			q.push(i);
			vis[i]=true;
		}
	}
	return true;
}

int solve(int n, unordered_map<int,vector<int>> g) {
	vector<bool> exists(n+1);
	vector<bool> hasBoss(n+1);
	for (int i=1; i<=n; i++) {
		for (int lackey : g[i]) {
			if (!hasBoss[lackey])
				hasBoss[lackey]=true;
			else {
				return 0;
			}

			exists[i]=true;
			exists[lackey]=true;
		}
	}
	int boss=0;
	int k=0;
	for (int i=1; i<=n; i++) {
		if (exists[i]) {
			if (!hasBoss[i]) {
				boss=i;
				k++;
			}
		}
	}
	if (k!=1) return 0;
	if (boss==0) return 0;

	if (works(g,boss)) {
		// cout << "works..." << endl;
		return boss;
	}
	else {
		return 0;
	}
}

int main() {
	unordered_map<int,vector<int>> g;
	int maxN=0;
	int x=0,y=0;
	vector<int> ans;
	while (x!=-1 && y!=-1) {
		cin>>x>>y;
		if (x==-1||y==-1) break;
		if (x!=0&&y!=0) {
			g[x].push_back(y);
			maxN=max(maxN,x);
			maxN=max(maxN,y);
		}
		else {
			ans.push_back(solve(maxN, g));
			maxN=0;
			g.clear();
			x=0;
			y=0;
		}
	}
	for (int i : ans) {
		if (i>0) {
			cout << i << endl;
		}
		else {
			cout << "INVALID" << endl;
		}
	}
	

}