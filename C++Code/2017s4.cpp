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



bool sortCost(pi a, pi b) {
	return a.S < b.S;
}

void printPi(pi p) {
	cout << "(" << p.F << ' ' << p.S << ") ";
}

void printG(vec<vec<pi>> g) {
	for (vec<pi> r : g) {
		for (pi p : r) {
			printPi(p);
		}
		cout << endl;
	}
}

int main() {
	int n,m,d; cin>>n>>m>>d;
	vec<vec<pi>> graph(n+1);
	
	vec<pi> hadAct;
	vec<vec<bool>> isAct1(n+1, *(new vec<bool>(n+1, false)));

	vec<int> costlyEdge = {-1,-1,-1};
	FOR(i,m) {
		int from, to, cost; cin>>from>>to>>cost;
		graph[from].PB({to,cost});
		graph[to].PB({from,cost});
		if (cost > costlyEdge[2]) {
			costlyEdge = {from,to,cost};
		}
		if (i+1<=n-1) {
			// cout << from << " to " << to << " act" << endl; 
			// cout << "act" << endl;
			isAct1[from][to] = true;
			isAct1[to][from] = true;
			hadAct.PB({from,to});
		}
		else {
			// cout << "deac" << endl;
			// cout << from << " to " << to << " is deactivated" << endl; 
		}
	}
	// cout << INT_MAX << endl;
	FOR(i,n) {
		sort(graph[i+1].begin(), graph[i+1].end(), sortCost);
	}

	if (costlyEdge[2] != 0) {
		for (int i=1; i<=graph.size(); i++) {
			vec<pi> r = graph[i];
			if (r.size()==0) continue;
			if (r.back().S == costlyEdge[2]) {
				graph[i][r.size()-1].S -= d;

				int from = i;
				int to = r.back().F;

				for (int o=0; o<graph[to].size(); o++) {
					pi p = graph[to][o];
					if (p.F==from) {
						graph[to][o].S -= d;
						break;
					}
				}
				
				break;
			}
		}
	}

	// create span tree
	vec<vec<int>> span(n+1);
	vec<int> selected = {1};
	uMap<int,bool> isSelected;
	isSelected[1]=true;

	vec<vec<bool>> isAct2(n+1, *(new vec<bool>(n+1,false)));
	vec<pi> needToAct;

	while (selected.size() < n) {
		int from = -1;
		pi nearest = {-1, INT_MAX};
		for (int select : selected) {
			for (pi p : graph[select]) {
				if (isSelected[p.F]) continue;
				if (p.S < nearest.S) {
					nearest = p;
					from = select;
					break;
				}
			}
		}
		selected.PB(nearest.F);
		isSelected[nearest.F] = true;

		int to = nearest.F;
		span[from].PB(to);
		span[to].PB(from);
		// cout << from << " to " << to << endl;

		isAct2[from][to] = true;
		isAct2[to][from] = true;

		needToAct.PB({from,to});

		// cout << from << " to " << to << endl;
	}

	int act=0, deAct=0;
	for (pi p : needToAct) {
		int from = p.F, to = p.S;
		if (isAct1[from][to] == false) {
			// cout << from << " to " << to << " need act " << endl;
			// cout << "because the old " << from << " to " << to << " is not act" << endl;
			act++;
		}
	}

	for (pi p : hadAct) {
		int from = p.F, to = p.S;
		if (isAct2[from][to] == false) {
			deAct++;
		}
	}


	// cout << "i need to activate " << act << " amount of pipes" << endl;
	// cout << "i need to deactivate " << deAct << " amount of pipes" << endl;

	int ans = max(act,deAct);
	cout << ans << endl;

	// printG(graph);

}