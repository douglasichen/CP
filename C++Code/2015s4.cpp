#include <bits/stdc++.h>
using namespace std;

int K,N,M,A,B;
unordered_map<int,vector<vector<int>>> g; // a -> b with data {b,t,h}

long long solve() {
	long long ans=-1;
	unordered_map<int,bool> vis; vis[A]=1;
	deque<vector<long long>> dq; // island, timePassed, hull size decrease;
	dq.push_back({A,0,0});

	while (!dq.empty()) {
		vector<long long> back=dq.back(); dq.pop_back();
		int island=back[0];
		long long timePassed=back[1];
		int hullDec=back[2];

		if (hullDec>=k) continue;
		if (island)

		vector<vector<int>> nexts=g[island];
		for (vector<int> data : nexts) {
			int next=data[0], time=data[1], nextHullDec=data[2];
			if (!vis[next]) {
				dq.push_front({next,timePassed + (long long)time, hullDec - nextHullDec});
				vis[next]=1;
			}
		}

	}


	return ans;
}

int main() {
	cin>>K>>N>>M;
	for (int i=0; i<M; i++) {
		int a,b,t,h; cin>>a>>b>>t>>h;
		g[a].push_back({b,t,h});
		g[b].push_back({a,t,h});
	}
	cin>>A>>B;
	
	long long ans=solve();
	cout << ans << endl;
}