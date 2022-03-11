#include <bits/stdc++.h>
using namespace std;

// bool sorter(vector<long long> &a, vector<long long> &b) {
// 	return a[1]>b[1];
// }

long long solve(long long N, vector<vector<long long>> G[], long long a, long long b) {
	long long sel=a;
	vector<bool> vis(N+1); vis[sel]=1;
	priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq; pq.push({sel,0});
	
	vector<long long> dists(N+1,INT_MAX);
	dists[a]=0;
	
	while (!pq.empty()) {
		pair<long long,long long> back=pq.top(); pq.pop();
		long long fromNode=back.first, fromDis=back.second;
		vis[fromNode]=1;
		if (fromNode==b) break;
		if (fromDis!=dists[fromNode]) continue;

		vector<vector<long long>> nxts=G[fromNode];
		for (vector<long long> nxt : nxts) {
			long long nxtNode=nxt[0], nxtDis=nxt[1], addNxtDis=nxtDis+fromDis;
			if (!vis[nxtNode] && addNxtDis<dists[nxtNode]) {
				dists[nxtNode]=min(dists[nxtNode],addNxtDis);
				pq.push({nxtNode,addNxtDis});
			}
		}
	}
	return dists[b];
}



int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	long long T; cin>>T;
	vector<long long> ans[T];
	for (long long i=0; i<T; i++) {
		unordered_map<string,long long> c2i;
		long long N; cin>>N;
		vector<vector<long long>> G[N+1];
		for (long long a=1; a<=N; a++) {
			string name; cin>>name;
			long long P; cin>>P;
			c2i[name]=a;

			for (long long o=0; o<P; o++) {
				long long b,c; cin>>b>>c;
				G[a].push_back({b,c});
			}
		}
		long long R; cin>>R;
		for (long long o=0; o<R; o++) {
			string s1,s2; cin>>s1>>s2;
			long long a=c2i[s1], b=c2i[s2];
			ans[i].push_back(solve(N,G,a,b));
		}
	}
	for (vector<long long> v : ans) {
		for (long long i : v) cout << i << endl;
	}
}