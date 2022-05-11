#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	double X;
	long long D,P;
	int N,K; cin>>N>>D>>K>>X; X=(100.0-X)/100.0;
	vector<long long> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	cin>>P;
	sort(V.begin(),V.end(),greater<long long>());
	for (int o=0; o<N; o++) {
		if (V[o]<P) break;
		while (K && V[o]>=P) K--,V[o]*=X;
	}
	bool ans=1;
	for (long long i : V) {
		if (i>=P) {
			ans=0;
			break;
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
}