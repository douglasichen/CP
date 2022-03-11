#include <bits/stdc++.h>
using namespace std;

int N;
string S;
unordered_map<int,vector<int>> g;
long long ans=0;

int done=0;
unordered_map<int,bool> dones;

void bfs(int start) {
	int ex=g[start].size();
	int goes=N-ex-done;
	ans+=goes;
	done++;
	dones[start]=1;
}

int main() {
	cin>>N>>S;
	for (int i=0; i<N-1; i++) {
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i=1; i<=N; i++) {
		bfs(i);
	}
	cout << ans-1 << endl; 
}