#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int N,K; cin>>N>>K;
	int V[N];
	for (int i=0; i<N; i++) cin>>V[i];

	int ans=0;
	
	long long tnd=0;
	for (int i=0; i<N; i++) {
		unordered_map<int,bool> has;
		long long d=0, nd=0;
		for (int o=i; o<N; o++) {
			if (!has[V[o]]) {
				d++;
				has[V[o]]=1;
			}
			if (d>=K) break;
			nd++;
		}
		tnd+=nd;
	}
	long long t=(N*N + N)/2;
	ans=t-tnd;
	cout << ans << endl;
}