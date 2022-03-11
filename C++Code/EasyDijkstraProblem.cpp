#include <bits/stdc++.h>
using namespace std;

bool sorter(vector<int> &a, vector<int> &b) {
	return a[1]>b[1];
}

long long solve(int N, vector<vector<int>> G[], int A, int B) {
	vector<bool> isSel(N+1);
	priority_queue<vector<int>, vector<vector<int>>, decltype(&sorter)> pq(sorter);	// node, dis
	pq.push({A,0});

	int cnt=0;
	while (cnt<N && !pq.empty()) {
		vector<int> top=pq.top(); pq.pop();
		int topNode=top[0], topDis=top[1];
		if (isSel[topNode]) continue;
		isSel[topNode]=1;
		cnt++;

		// check
		if (topNode==B) return topDis;

		// set new gen
		for (vector<int> child : G[topNode]) {
			int childNode=child[0], childCost=child[1];
			if (!isSel[childNode]) {
				pq.push({childNode,topDis+childCost});
			}
		}
	}

	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	long long ans[T];
	for (int i=0; i<T; i++) {
		int N,K; cin>>N>>K;
		vector<vector<int>> G[N+1];
		for (int o=0; o<K; o++) {
			int a,b,c; cin>>a>>b>>c;
			G[a].push_back({b,c});
		}
		int A,B; cin>>A>>B;
		ans[i]=solve(N,G,A,B);
	}
	for (long long i : ans) {
		if (i==-1) cout << "NO" << endl;
		else cout << i << endl;
	}
	
}