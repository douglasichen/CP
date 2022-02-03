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

void dfs(unordered_map<char, vector<char>> graph, char node) {
	cout << node << ' ';
	for (auto c : graph[node]) dfs(graph, c);
}

void bfs(unordered_map<char, vector<char>> graph, char node) {
	deque<char> dq; dq.push_back(node);
	while (!dq.empty()) {
		char back = dq.back(); dq.pop_back();
		cout << back << ' ';
		for (char c : graph[back]) dq.push_front(c);
	}
	cout << endl;

} 

bool hasPath(unordered_map<char, vector<char>> graph, char start, char end) {
	vector<bool> visited(26);
	stack<char> s; s.push(start);
	while (!s.empty()) {
		char top = s.top(); s.pop();
		for (char c : graph[top]) {
			if (c == end) return true;
			if (!visited[c-'a']) {
				visited[c-'a'] = true;
				s.push(c);
			}
		}
	}
	return false;
}


bool hasPathUndirected(unordered_map<char, vector<char>> graph, char start, char end, vector<bool> visited) {
	if (start == end) return true;
	for (char c : graph[start]) {
		if (!visited[c-'a']) {
			visited[c-'a'] = true;
			if (hasPathUndirected(graph, c, end, visited)) return true;
		}
	}
	return false;
}


vector<bool> findComp(unordered_map<int, vi> graph, vector<bool> visited, int n) {
	visited[n] = true;
	for (int i : graph[n]) {
		if (!visited[i]) visited = findComp(graph, visited, i);
	}
	return visited;
}

int countComponents(unordered_map<int, vi> graph, vector<bool> visited) {
	int comps = 0;
	for (pair<int, vi> p : graph) {
		if (!visited[p.F]) {
			visited = findComp(graph, visited, p.F);
			++comps;
		}
	}
	return comps;
}

int shortestPath(unordered_map<char, vector<char>> graph, char start, char end, int dis) {
	vector<bool> visited('z'+1);
	deque<pair<char,int>> dq;
	dq.push_back({start, 0});
	while (!dq.empty()) {
		pair<char,int> back = dq.back();
		if (back.F == end) return back.S;
		dq.pop_back();
		for (char c : graph[back.F]) {
			if (!visited[c]) {
				visited[c] = true;
				dq.push_front({c,back.S+1});
			}
		}
	}
	return -1;
}

int main() {
	// unordered_map<char, vector<char>> graph;
	// graph['a'] = {'b','c'};
	// graph['b'] = {'d'};
	// graph['c'] = {'e'};
	// graph['d'] = {'f'};
	// graph['e'] = {};
	// graph['f'] = {};

	// char start = 'a';

	// dfs(graph, start); cout << endl;
	// bfs(graph, start);

	// unordered_map<char, vector<char>> graph;
	// graph['f'] = {'g','i'};
	// graph['g'] = {'h'};
	// graph['h'] = {};
	// graph['i'] = {'g','k'};
	// graph['j'] = {'i'};
	// graph['k'] = {}; 

	// cout << hasPath(graph, 'k', 'i') << endl;

	// vector<pi> edges = {
	// 	{'i', 'j'},
	// 	{'k', 'i'},
	// 	{'m', 'k'},
	// 	{'k', 'l'},
	// 	{'o','n'},
	// };
	// unordered_map<char, vector<char>> graph;
	// for (pi edge : edges) {
	// 	graph[edge.F].PB(edge.S);
	// 	graph[edge.S].PB(edge.F);
	// }
	// cout << hasPathUndirected(graph, 'o', 'k', *(new vector<bool>(26))) << endl;

	// unordered_map<int, vi> graph;
	// graph[3] = {};
	// graph[4] = {6};
	// graph[6] = {4,5,7,8};
	// graph[8] = {6};
	// graph[7] = {6};
	// graph[5] = {6};
	// graph[1] = {2};
	// graph[2] = {1};
	// cout << countComponents(graph, *(new vector<bool>(graph.size()+1))) << endl;

	
	vector<pi> edges = {
		{'a','b'},
		{'a','c'},
		{'a','f'},
		{'b','g'},
		{'c','d'},
		{'d','h'},
		{'e','f'},
		{'f','g'},

	};
	unordered_map<char, vector<char>> graph;
	for (pi edge : edges) {
		graph[edge.F].PB(edge.S);
		graph[edge.S].PB(edge.F);
	}
	cout << shortestPath(graph, 'a', 'g', 0);

}