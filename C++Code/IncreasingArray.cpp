#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N);
	unsigned long long ans=0;
	for (int i=0; i<N; i++) cin>>V[i];
	for (int i=1; i<N; i++) {
		if (V[i]<V[i-1]) {
			int dif=V[i-1]-V[i];
			ans+=dif;
			V[i]=V[i-1];
		}
	}
	cout << ans << endl;
}