#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<vector<int>> V(N,vector<int>(2));
	for (int i=0; i<N; i++) cin>>V[i][0]>>V[i][1];
	sort(V.begin(),V.end());

	long long ans=0;
	for (int i=0; i<N; i++) {
		vector<int> v=V[i];
		auto it=lower_bound(V.begin(), V.end(), {v[0]+1,V[1]+1});
		
	}
}