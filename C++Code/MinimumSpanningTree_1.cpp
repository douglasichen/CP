#include <bits/stdc++.h>
using namespace std;

bool sorter(vector<int> &a, vector<int> &b) {
	return a[1]>b[1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N,M; cin>>N>>M;
	vector<vector<int>> G[N+1];
	for (int i=0; i<M; i++) {
		int a,b,c; cin>>a>>b>>c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}

	// set
	vector<bool> isSel(N+1); isSel[1]=1;
	priority_queue<vector<int>, vector<vector<int>>, decltype(&sorter)> pq(sorter);
	for (vector<int> child : G[1]) {
		if (!isSel[child[0]]) pq.push(child);
	}

	// solve
	long long ans=0;
	int cnt=1;
	while (cnt<N) {
		vector<int> top=pq.top(); pq.pop();
		int topNode=top[0], topCost=top[1];
		if (isSel[topNode]) continue;
		isSel[topNode]=1;
		ans+=topCost;
		cnt++;

		for (vector<int> child : G[topNode]) {
			if (!isSel[child[0]]) {
				pq.push(child);
			}
		}
	}
	cout << ans << endl;
}