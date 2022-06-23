#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	for (int t=0, N; t<T; t++) {
		cin>>N;
		vector<int> V(N+1);
		for (int i=1; i<=N; i++) cin>>V[i];
		long long ans=0;
		for (int a=1; a<=N; a++) {
			int c=0, l=a, sm=0;
			for (int b=a; b<=N; b++) {
				if (V[b]==0) l=b;
				if (V[b]-V[b-1]!=1) {
					c++;
					sm+=V[b-1]
					ans+=c+sm;
				}

			}
		}
		cout << ans << endl;
	}	
}