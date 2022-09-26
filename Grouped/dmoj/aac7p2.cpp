#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<vector<int>> G(N+1);
	for (int i=1,a,b; i<N; i++)
		cin>>a>>b,
		G[a].push_back(b),
		G[b].push_back(a);

	cout << G[1].size()+1 << endl;
	
	vector<bool> done(N+1);
	for (int i : G[1]) cout << 1 << endl, done[i]=1;

	cout << N-G[1].size() << endl;
	for (int i=2; i<=N; i++) 
		if (!done[i])
			cout << 1 << ' ' << i << endl;	
}