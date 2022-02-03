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

const int INF = INT_MAX; // weight INF means there is no edge

struct Edge {
    int w = INF, to = -1;
};

void prim(int n, vec<vec<int>> adj) {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    FOR(i,n) {
        int v = -1;
        FOR(j, n) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w)) {
                v = j;
			}
        }

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }

    cout << total_weight << endl;
}


void printG(vec<vec<int>> g) {
	for (vec<int> r : g) {
		for (int i : r) cout << i << ' ';
		cout << endl;
	}
}

void printPi(pi p) {
	cout << p.F << ' ' << p.S << endl;
}

void solve(int n, vec<vec<pi>> graph, int start) {
	vec<vec<int>> minSpan(n);

	uMap<int,bool> isSelected;
	vec<int> selected = {start};

	isSelected[selected[0]]=true;
	int totalW = 0;
	while(selected.size() < n) {
		int from = -1;
		pi nearest = {-1, INF};
		// get nearest node without sorted
		/*
		for (int select : selected) {
			for (pi node : graph[select]) {
				if (isSelected[node.F]) continue;
				if (node.S < nearest.S) {
					from = select;
					nearest = node;
				}
			}
		}
		*/
		
		// get nearest node with sorted
		for (int select : selected) {
			FOR(i, graph[select].size()) {
				pi node = graph[select][i];
				if (!isSelected[node.F]) {
					if (node.S < nearest.S) {
						nearest = node;
						from = select;
					}
					graph[select].erase(graph[select].begin(), graph[select].begin() + i);
					break;
				}
			}
		}

		if (nearest.F==-1) break;
		selected.PB(nearest.F);
		isSelected[nearest.F] = true;
		totalW += nearest.S;
		cout << from << " to " << nearest.F << endl;
		minSpan[from].PB(nearest.F);
		minSpan[nearest.F].PB(from);
	}
	for (int i : selected) cout << i << ' ';
	cout << endl;
	cout << "weight: " << totalW << endl; 

}

bool sortFunc(pi a, pi b) {
	return a.S < b.S;
}

int main() {
	

	int n, m; cin>>n>>m;
	// vec<vec<int>> g = *(new vec<vec<int>> (n, *(new vec<int>(n))));
	vec<vec<pi>> g(n);
	// vec<int> minEd(n, INT_MAX);
	FOR(i,m) {
		pi p; cin>>p.F>>p.S;
		int c; cin>>c;
		// if (c < minEd[p.F]) minEd[p.F] = c;
		// if (c < minEd[p.S]) minEd[p.S] = c; 
		// g[p.F][p.S]=c;
		// g[p.S][p.F]=c;
		g[p.F].PB({p.S,c});
		g[p.S].PB({p.F,c});
	}
	FOR(i,n) {
		sort(g[i].begin(), g[i].end(), sortFunc);
	}
	// prim(n, g);

	// for (int i : minEd) cout << i << ' ';
	// cout << endl;
	// // printG(g);

	// int start=0;

	solve(n, g, 1);
}