#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<vector<int>> F(M+1);
	for (int i=1,inp; i<=N; i++) {
		cin>>inp;
		F[inp].push_back(i);
	}
	int K=N/2;
	for (int i=1; i<=M; i++) {
		auto it=lower_bound(V[i].begin(),V[i].end(),K);
		int a=it-V[i].begin()+1;
		
	}
}