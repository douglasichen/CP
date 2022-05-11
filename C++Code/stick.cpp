#include <bits/stdc++.h>
using namespace std;

int N,L;
vector<vector<int>> G(1001);


void solve() {
	
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>L;
	for (int i=0,a,b; i<N; i++) {
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i=1; i<)

}