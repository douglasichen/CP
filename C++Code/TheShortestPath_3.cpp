#include <bits/stdc++.h>
using namespace std;

bool sorter(vector<int> &a, vector<int> &b) {
	return a[1]>b[1];
}

int solve(int N, vector<vector<int>> G[], int A, int B) {
	vector<int> MD(N+1,INT_MAX);
	vector<bool> isSel(N+1);
	map<int, stack<int>> M; M[0].push(A);

	int cnt=0;
	while (cnt<N && !M.empty()) {
		int closeDis=M.begin()->first, closeNode=M.begin()->second.top();
		M.begin()->second.pop();
		if (M.begin()->second.size()==0) M.erase(M.begin());
		if (isSel[closeNode]) continue;
		isSel[closeNode]=1;

		// check
		if (closeNode==B) return closeDis;
		
		// next
		for (vector<int> child : G[closeNode]) {
			int childNode=child[0], childCost=child[1], childDis=closeDis+childCost;
			if (!isSel[childNode] && childDis<MD[childNode]) {
				M[childDis].push(childNode);
				MD[childNode]=childDis;
			}
		}
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	vector<long long> ans[T];
	for (int i=0; i<T; i++) {
		unordered_map<string,int> c2i;
		int N; cin>>N;
		vector<vector<int>> G[N+1];
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
	for (vector<long long> v : ans) {
		for (long long i : v) cout << i << endl;
	}
}