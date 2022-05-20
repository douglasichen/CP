#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	for (int i=0,N,K; i<T; i++) {
		cin>>N>>K;
		vector<int> V(N);
		for (int o=0; o<N; o++) cin>>V[o];
		sort(V.begin(),V.end());
		bool gd=0;
		int a=0,b=1;
		for (; b<N; b++) {
			while (a<b && V[b]-V[a]>K) a++;
			if (V[b]-V[a]==K) {
				gd=1;
				break;
			}
		}
		if (gd) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}