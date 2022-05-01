#include <bits/stdc++.h>
using namespace std;

int N,M,C;
vector<vector<int>> G;
vector<int> V;


void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M>>C;
	V=vector<int>(N+1);
	G=vector<vector<int>>(N+1);
	for (int i=1; i<=N; i++) cin>>V[i]
	for (int i=0,a,b; i<M; i++) {
		cin>>a>>b;
		G[a].push_back(b);
	}
}