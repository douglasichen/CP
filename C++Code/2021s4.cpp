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


void printG(vec<vec<int>> g) {
	FOR(i,g.size()) {
		vec<int> row = g[i];
		cout << i << ": ";
		for (int o : row) cout << o << ' ';
		cout << endl;
	}
	cout << endl;
}

int bfs(int n, vec<vec<int>> graph) {
	int start = 1, goal = n;

	// pairs hold node and distance
	uMap<int,bool> visited;
	deque<pi> q;
	q.PB({1,0});

	while (!q.empty()) {
		pi back = q.back();
		q.pop_back();
		if (back.F == goal) return back.S;
	
		visited[back.F]=true;

		vec<int> stations = graph[back.F];
		// cout << "i can visit stations: ";
		for (int station : stations) {
			if (visited[station]) continue;
			// cout << "go from " << back.F << " to " << station << endl;
			// cout << station << ' ';
			q.push_front({station, back.S+1});
		}
		// cout << endl;
	}
	return -1;
}

int solve(int n, int w, vec<int> train, vec<vec<int>> walkGraph) {
	
	FOR(i,n-1) {
		int station1 = train[i];
		int station2 = train[i+1];
		walkGraph[station1].PB(station2);
	}
	// printG(walkGraph);
	return bfs(n, walkGraph);
	
	return 0;
}

vec<int> nextDay(vec<int> train, pi day) {
	int temp = train[day.F-1];
	train[day.F-1] = train[day.S-1];
	train[day.S-1] = temp;
	return train;
} 

int main() {
	int n, w, d;
	vec<vec<int>> graph;
	cin>>n>>w>>d;
	vec<vec<int>> empGraph(n+1);
	graph = empGraph;
	FOR(i,w) {
		int a,b; cin>>a>>b;
		graph[a].PB(b);
	}
	vec<int> train(n);
	FOR(i,n) {
		cin >> train[i];
	}
	vec<pi> days(d);
	FOR(i,d) {
		cin>>days[i].F>>days[i].S;
	}
	
	for (pi day : days) {
		train = nextDay(train, day);
		// cout << "train: ";
		// for (int i : train) cout << i << ' ';
		// cout << endl;
		int k = solve(n, w, train, graph);
		cout << k << endl;
	}
}