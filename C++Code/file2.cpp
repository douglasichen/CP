#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

int n,w,d;
int startLocation;
vector<vi> graph;
vi distances;

vi swaps;

void findDistances(int loc, int prevDistance, vi visited) {
	for (int i=0; i<graph[loc].size(); i++) {
		if (graph[loc][i]==1) {
			// if (i+1==n) {
			// 	ans = distances[i];
			// 	break;
			// }
			if (visited[i]==1) continue;
			if (prevDistance<distances[i]) {
				distances[i] = prevDistance+1;
				visited[i] = 1;
				findDistances(i, distances[i], visited);
				visited[i] = 0;
			}
		}
	}
}

void printG() {
	for (int y=0; y<graph.size(); y++) {
		for (int x=0; x<graph.size(); x++) {
			cout<<graph[y][x]<<' ';
		}
		cout<<endl;
	}
}

int main() {
	cin>>n>>w>>d;
	graph = *(new vector<vi>(n, *(new vector<int>(n,0))));
	distances = *(new vi(n,999999));

	vi stations(n);
	
	for (int i=0; i<w; i++) {
		int from,to; cin>>from>>to;
		graph[from-1][to-1] = 1;
	}
	vector<vi> prevGraph = graph;
	int prevStation=0;
	for (int i=0; i<n; i++) {
		int station; cin>>station;
		station-=1;
		stations[i] = station;
		if (i!=0) graph[prevStation][station] = 1;
		else startLocation = station;
		prevStation = station;
	}
	// vi visited(n,0);
	// findDistances(startLocation, 0, visited);
	// cout<<distances[n-1]<<endl;
	// // printG();
	
	for (int i=0; i<d; i++) {
		pi swap; cin>>swap.F>>swap.S;
		swap.F-=1;
		swap.S-=1;

		graph = prevGraph;
		distances = *(new vi(n,200001));
		// cout<<"stations: ";
		// for (int i : stations) cout<<i<<' ';
		// cout<<endl;
		// cout<<"swap: "<<swap.F<<" "<<swap.S<<endl;
		int temp = stations[swap.F];
		stations[swap.F] = stations[swap.S];
		stations[swap.S] = temp;
		int prevStation = 0;
		for (int i=0; i<n; i++) {
			int station = stations[i];
			if (i!=0) graph[prevStation][station] = 1;
			else startLocation = station;
			prevStation = station;
		}
		// printG();
		// cout<<"stations: ";
		// for (int i : stations) cout<<i<<' ';
		// cout<<endl;
		vi visited(n,0);
		findDistances(stations[0], 0, visited);
		cout<<distances[n-1]<<endl;
	}
}