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
	
	unordered_map<int, bool> vr;
	stack<int> s;
	s.push(p);
	
	while (!s.empty()) {
		int back = s.top();
		s.pop();
		
		int fNext=0;
		for (int i : graph[back]) {
			if (vr[i]) continue;
			s.push(i);
			vr[i] = true;
			fNext++;
		}
		if (isPho[back]) farPho = back;
		if (fNext==0) break;
	}
	return farPho;
}


int bfs(int p) {
	int dis = 0;
	int phoC=pho.size();
	unordered_map<int,int> disFromSubRoot;
	unordered_map<int,bool> visited;
	unordered_map<int,bool> btSubRoots;
	deque<vi> q;
	q.push_back({p,0});

	while (!q.empty()) {
		vi back = q.back();
		q.pop_back();

		visited[back[0]] = true;
		
		int nextNodesC = graph[back[0]].size() - (back[0]!=p);

		if (isPho[back[0]]) {
			phoC--;

			dis += back[1];
			back[1] = 0;
			
			// if (phoC>0) {
			// 	dis += disFromSubRoot[back[0]];
			// }
		}
		// if (nextNodesC>=2) {
		// 	dis += back[1];
		// 	back[1] = 0;
		// }

		

		for (int i : graph[back[0]]) {
			if (visited[i]) continue;

			if (nextNodesC>=2) {
				back[1] = 0;
				disFromSubRoot[i] = 1;
			}
			else {
				disFromSubRoot[i] = disFromSubRoot[back[0]]+1;
			}
			q.push_front({i,back[1]+1});
			
		}
		
		if (phoC==0) break;
		
	}
	return dis;
}

int solve() {
	int dis=0;

	int fPho = endPho(pho[0]);

	dis = bfs(fPho);

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

	cout << solve() << endl;
}