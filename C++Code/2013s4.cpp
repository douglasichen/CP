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

bool bfs(vector<vi> g, int a, int b) {
	unordered_map<int,bool> visited;
	deque<int> dq;
	dq.PB(a);
	while (!dq.empty()) {
		int back = dq.back();
		dq.pop_back();

		if (back==b) return 1;

		for (int i : g[back]) {
			if (!visited[i]) dq.push_front(i);
			visited[i]=1;
		}
	}
	return 0;
}

int main() {
	ll n,m; cin>>n>>m;
	vector<vi> g(n+1);
	FOR(i,m) {
		int x,y; cin>>x>>y;
		g[x].PB(y);
	}
	int p,q; cin>>p>>q;
	bool boolAns = bfs(g, p, q);
	string ans = (boolAns ? "yes" : "no");
	if (!boolAns) {
		bool check=bfs(g,q,p);
		if (!check) ans = "unknown";
	}
	cout << ans << endl;
}