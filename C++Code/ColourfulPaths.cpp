#include <bits/stdc++.h>
using namespace std;

int N,M,A,B,C,D;
unordered_map<int,vector<int>> g;

unordered_map<int,bool> cut;

unordered_map<int,unordered_map<int,int>> loc2ind;

void Cut() {
	unordered_map<int,bool> vis;
	unordered_map<int,int> prev;
	deque<int> dq;
	dq.push_back(A);
	vis[A]=1;

	while (!dq.empty()) {
		int back=dq.back(); dq.pop_back();

		if (back==B) {
			break;
		}

		for (int node : g[back]) {
			if (!vis[node]) {
				dq.push_front(node);
				prev[node]=back;
				vis[node]=1;
			}
		}
	}
	
	int node=B;
	while (prev[node]!=0) {
		node=prev[node];
		cut[node]=1;
	}
	cut[A]=1;
}

int bfs() {
	unordered_map<int,bool> vis;
	unordered_map<int,int> prev;
	deque<vector<int>> dq; // node, dis
	dq.push_back({C,0});
	vis[C]=1;

	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();

		if (back[0]==D) {
			return back[1];
		}

		for (int node : g[back[0]]) {
			if (!vis[node] && !cut[node]) {
				dq.push_front({node,back[1]+1});
				vis[node]=1;

				prev[node]=back[0];
			}
		}
	}

	int node=B;
	while (prev[node]!=0) {
		loc2ind[node][prev[node]]=2;
		loc2ind[prev[node]][node]=2;
		node=prev[node];
	}
	

	return -1;
}

int solve() {
	Cut();
	return bfs();
}

int main() {
	cin>>N>>M;
	vector<vector<int>> rs;
	for (int i=0; i<M; i++) {
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		rs.push_back({a,b});
	}

	cin>>A>>B>>C>>D;

	int ans=solve();
	cout << ans << endl;

	for (vector<int> r : rs) {
		if (loc2ind[r[0]][r[1]]==2) {
			cout << 2 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
}