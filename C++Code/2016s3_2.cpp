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


int n,m;
vi pho;
unordered_map<int,bool> isPho;
unordered_map<int, vi> graph;


int endPho(int p) {
	int farPho = p;
	
	unordered_map<int, bool> visited;
	deque<int> q;
	q.push_back(farPho);

	while (!q.empty()) {
		int back = q.back();
		q.pop_back();

		visited[back]=true;

		if (isPho[back]) {
			farPho=back;
		}

		for (int i : graph[back]) {
			if (visited[i]) continue;
			q.push_front(i);
		}
	}


	return farPho;
}



int solve(int p) {
	int dis=0;


	// roots(pho[0]);
	// weights(pho[0]);

	// int fPho = endPho(pho[0]);
	int fPho = p;
	// cout << fPho << endl;
	unordered_map<int, bool> visited;
	unordered_map<int,bool> visitedPho;
	deque<pi> q;
	q.push_back({fPho,0});
	int phoC = pho.size();
	while (!q.empty()) {
		pi back = q.back();
		q.pop_back();

		visited[back.F] = true;
		if (isPho[back.F] && !visitedPho[back.F]) {

			dis+=back.S;
			// cout << "found pho " << back.F << ": distance is now " << dis << endl;
			phoC--;
			if (phoC==0) return dis;

			visitedPho[back.F] = true;

			q.clear();
			visited.clear();

			q.push_back({back.F,0});
			
			continue;
		}

		for (int i : graph[back.F]) {
			if (visited[i]) continue;
			q.push_front({i, back.S+1});
		}
	}

	return dis;
}

int main() {
	cin>>n>>m;

	FOR (i,m) {
		int p; cin>>p;
		isPho[p]=true;
		pho.PB(p);
	}

	FOR(i,n-1) {
		int a,b; cin>>a>>b;
		graph[a].PB(b);
		graph[b].PB(a);
	}

	int dis = solve(pho[0]);
	for (int i=1; i<m; i++) {
		int nd = solve(pho[i]);
		if (nd<dis) dis = nd;
	}

	cout << dis << endl;

}