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

int n, m;
unordered_map<int,vi> tree;
unordered_map<int,bool> isPho;
int pho;

unordered_map<int,int> depth;
int longestPath=-1;



void condenseTree() {
	FOR(i,n) {
		int current = i;
		while (tree[current].size()==1) {
			if (isPho[current]) break;
			int next = tree[current][0];
			tree[next].erase(find(tree[next].begin(), tree[next].end(), current));
			tree[current].clear();
			current = next;
		}
	}
}

void getLongestPath(int current, int last, int currentDepth) {
	depth[current] = currentDepth;
	longestPath = max(longestPath, currentDepth);
	FOR(i, tree[current].size()) {
		if (tree[current][i] == last) continue;
		getLongestPath(tree[current][i], current, currentDepth+1);
	}
}

int getTreeWeight() {
	int weight = 0;
	FOR(i,n) weight += tree[i].size();
	return weight;
}

int main() {
	cin >> n >> m;
	FOR (i,m) {
		cin >> pho;
		isPho[pho] = true;
	}
	FOR(i,n-1) {
		int a, b; cin >> a >> b;
		tree[a].PB(b);
		tree[b].PB(a);
	}
	condenseTree();
	getLongestPath(pho, -1, 0);
	FOR(i,n) {
		if (depth[i] != longestPath) continue;
		getLongestPath(i, -1, 0);
		break;
	}
	int treeWeight = getTreeWeight();
	int ans = treeWeight - longestPath;
	cout << ans << endl;
}