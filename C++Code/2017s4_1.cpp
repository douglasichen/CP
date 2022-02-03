#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define uMap unordered_map
#define vec vector
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(x,n) for(int x = 0; x < n; ++x)
#define INF INT_MAX

int n,m,d;
vec<vec<pi>> graph;

vec<vec<bool>> activeA, activeB;
vec<pi> actA, actB;

ll graphW=0;
ll spanW=0;

vec<vec<int>> calcSpan() {
	vec<vec<int>> span(n+1);

	int start = 1;
	uMap<int,bool> isSel;
	isSel[start] = true;
	vec<int> selected = {start};

	while (selected.size() < n) {
		int from = -1;
		pi closest = {-1, INF};
		for (int sel : selected) {
			for (pi next : graph[sel]) {
				if (isSel[next.F]) continue;
				if (next.S < closest.S) {
					closest = next;
					from = sel;
				}
			}
		}

		// found a close city
		int to = closest.F;
		if (to!=-1) {
			isSel[to]=true;
			selected.PB(to);
			
			span[from].PB(to);
			span[to].PB(from);

			activeB[from][to]=true;
			activeB[to][from]=true;
			actB.PB({from,to});
			
			spanW += (ll)closest.S;

			// cout << from << " to " << closest.F << " costs: " << closest.S << endl;
		}
	}
	return span;
}

int findAct() {
	int ans=0;
	for (pi p : actB) {
		if (!activeA[p.F][p.S]) ans++;
	}
	return ans;
}

int findDeact() {
	int ans=0;
	for (pi p : actA) {
		if (!activeB[p.F][p.S]) ans++;
	}
	return ans;
}

int main() {
	cin>>n>>m>>d;

	activeA = *(new vec<vec<bool>>(n+1, *(new vec<bool>(n+1))));
	activeB = activeA;

	vec<vec<pi>> emp(n+1);
	graph = emp;
	
	// cost, a1, a2, b1, b2;
	vec<int> costly = {0,-1,-1,-1,-1};

	FOR(i,m) {
		int a,b,c; cin>>a>>b>>c;
		graph[a].PB(MP(b,c));
		graph[b].PB(MP(a,c));
		
		if (c>costly[0]) {
			costly = {c, a, graph[a].size()-1, b, graph[b].size()-1};
		}

		if (i+1<=n-1) {
			activeA[a][b]=true;
			activeA[b][a]=true;
			actA.PB({a,b});
			graphW+=(ll)c;
		}
	}

	int cost = costly[0], a1 = costly[1], a2 = costly[2], b1 = costly[3], b2 = costly[4];
	int change = cost-d;
	change = max(0,change);
	graph[a1][a2].S = change;
	graph[b1][b2].S = change;
	
	// cout << graphW << endl;
	// cout << "change: " << change << endl;
	int from = a1, to = graph[a1][a2].F;
	if (activeA[from][to]) {
		ll temp = graphW-d;
		graphW = max((ll)0,temp);
	}


	vec<vec<int>> mSpan = calcSpan();
	int toAct = findAct();
	int toDeact = findDeact();

	int ans=0;
	if (graphW!=spanW) ans=max(toAct, toDeact);
	// cout << graphW << ' ' << spanW << endl;

	cout << ans << endl;

}