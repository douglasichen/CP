#include <bits/stdc++.h>
using namespace std;

bool sorter(vector<int> a, vector<int> b) {
	return a[1]<b[1];
}

int solve(int N, unordered_map<int,vector<vector<int>>> G, int a, int b) {
	int ans=0;
	vector<vector<int>> D=*(new vector<vector<int>>(N+1, *(new vector<int>(2,INT_MAX)))); // cost from a, prev node
	D[1]={0,1};
	
	
	priority_queue<vector<int>, vector<vector<int>>, decltype(&sorter)> pq(sorter);	// node, dis
	pq.push({a,0});

	while (!pq.empty()) {
		vector<int> top=pq.top(); pq.pop();
		int from=top[0], fDis=top[1];
		vector<vector<int>> nexts=G[from];
		for (vector<int> next : nexts) {
			int to=next[0], toDis=fDis+next[1], oDis=D[to][0];
			if (toDis<oDis) {
				D[to]={toDis,from};
				pq.push({to,toDis});
			}
		}
	}
	return D[b][0];
}



int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	vector<int> ans[T];
	for (int i=0; i<T; i++) {
		unordered_map<string,int> c2i;
		unordered_map<int,vector<vector<int>>> G;
		int N; cin>>N;
		for (int a=1; a<=N; a++) {
			string name; cin>>name;
			int P; cin>>P;
			c2i[name]=a;

			for (int o=0; o<P; o++) {
				int b,c; cin>>b>>c;
				G[a].push_back({b,c});
			}
		}
		int R; cin>>R;
		for (int o=0; o<R; o++) {
			string s1,s2; cin>>s1>>s2;
			int a=c2i[s1], b=c2i[s2];
			ans[i].push_back(solve(N,G,a,b));
		}
	}
	for (vector<int> v : ans) {
		for (int i : v) cout << i << endl;
	}
}