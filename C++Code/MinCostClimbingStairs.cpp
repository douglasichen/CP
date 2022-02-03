#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef vector<vector<int>> vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(x,n) for(int x = 0; x < n; ++x)

#define printV(v) FOR(x,v.size()) cout<<v[x]<<' '; cout<<endl;


void solve() {

}

int bfs(unordered_map<int, vi> tree, vector<int>& cost, int root) {
	int ans=1000001;

	deque<pair<vi,int>> branches;
	branches.PB({tree[root], cost[root]});
	while (!branches.empty()) {
		pair<vi,int> back = branches.back();
		branches.pop_back();
		

		for (int i : back.F) {
			// cout << i << endl;
			if (i>=cost.size()) {
				// cout << "ee" << endl;
				if (back.S < ans) ans = back.S; 
			}
			else branches.push_front({tree[i], back.S+cost[i]});
			// cout << i << endl;
			// branches.push_front({tree[i], back.S+i});
		}
	}
	return ans;
}

int minCostClimbingStairs(vector<int>& cost) {
	unordered_map<int,pair<vi,bool>> tree;
	for (int i=0; i<cost.size(); i++) {
		tree[i].F.PB(i+1);

		if (i<cost.size()-1) {
			tree[i].F.PB(i+2);
		}
	}
	int startFromFirst = bfs(tree, cost, 0);
	int startFromSecond = bfs(tree, cost, 1);
	
	return min(startFromFirst, startFromSecond);
}

int main() {
	vi v = {1,100,1,1,1,100,1,1,100,1};
	cout << minCostClimbingStairs(v) << endl;
}