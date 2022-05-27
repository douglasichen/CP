#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	vector<vector<int>> psa(21,vector<int>(N+1));
	vector<int> V(N+1);
	for (int i=1; i<=N; i++) {
		string s; cin>>s;
		V[i]=s.size();
		psa[V[i]][i]++;
	}
	for (int i=2; i<=20; i++) {
		for (int o=1; o<=N; o++) {
			psa[i][o]+=psa[i][o-1];
		}
	}

	long long cnt=0;
	for (int i=1; i<N; i++) {
		cnt+=psa[V[i]][min(i+K,N)]-psa[V[i]][i];
	}
	cout << cnt << endl;
}
