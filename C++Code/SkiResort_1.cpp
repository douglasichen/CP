#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<vector<vector<int>>> g;
vector<int> sv;
vector<int> ans;

void trav(int skill) {
	int start=1;
	int node=start;
	
	while (node!=0) {
		ans[node]++;
		
		vector<vector<int>> children = g[node];
		if (children.size()==0) break;

		vector<long long> bestDiffer={0,LLONG_MAX};
		unordered_map<long long,vector<int>> minDifOfDiffer;

		for (vector<int> child : children) {
			int childNode = child[0];
			int childDific = child[1];

			// store all differences
			long long d = abs((long long)skill-(long long)childDific);
			
			// node with least absolute difference
			if (d<bestDiffer[1])
				bestDiffer={(long long)childNode, d};

			// best dif from differ
			if (minDifOfDiffer.count(d)==0)
				minDifOfDiffer[d]={childNode,childDific};
			else {
				if (childDific < minDifOfDiffer[d][1])
					minDifOfDiffer[d]={childNode,childDific};
			}
			
		}
		if (bestDiffer[0]==0) break;

		int nextNode=(int)bestDiffer[0];

		if (minDifOfDiffer[bestDiffer[1]].size()>1) {
			vector<int> bestOfTied=minDifOfDiffer[bestDiffer[1]];
			nextNode = bestOfTied[0];
		}

		// next node
		node=nextNode;
	}
}

void solve() {
	for (int i=1; i<=k; i++) {
		trav(sv[i]);
	}
}

int main() {
	cin>>n>>k;
	g = *(new vector<vector<vector<int>>>(n+1));
	sv = *(new vector<int>(k+1));
	ans = *(new vector<int>(n+1));
	for (int i=1; i<=n-1; i++) {
		int a,b,d; cin>>a>>b>>d;
		g[a].push_back({b,d});
	}
	for (int i=1; i<=k; i++) {
		cin>>sv[i];
	}
	
	solve();

	for (int i=1; i<=n; i++) {
		cout << ans[i];
		if (i!=n) cout << ' ';
	}
	cout << endl;
}