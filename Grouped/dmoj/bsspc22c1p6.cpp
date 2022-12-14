#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ull unsigned long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<vector<int>> V(N, vector<int>(2));
	for (int i=0; i<N; i++) {
		cin>>V[i][0]>>V[i][1];
	}
	ull INF=1e18;
	ull ans=0,sm=0;
	vector<ull> mn={0,INF};
	vector<int> vis(N);
	for (ull X=0; X<M; X++) {
		mn={0,INF};
		for (int i=0; i<N; i++) {
			if (!vis[i]) {
				sm=V[i][0]*X + V[i][1];
				if (sm<mn[1])
					mn={(ull)i,sm};
			}	
		}
		vis[mn[0]]=1;
		ans+=mn[1];
	}
	cout << ans << endl;
}