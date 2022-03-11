#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int N,M; cin>>N>>M;
	int R[N],C[M];
	for (int i=0; i<N; i++) cin>>R[i];
	for (int i=0; i<M; i++) cin>>C[i];
	
	int ans=0;
	// unordered_map<int,bool> rGone, cGone;
	// for (int y=0; y<N; y++) {
	// 	for (int x=0; x<M; x++) {
	// 		if (R[y]==-1 || C[x]==-1) continue;
	// 		if (rGone[y] || cGone[x]) continue;
	// 		long long t1=(long long)R[y]+(long long)x, t2=(long long)C[x]+(long long)y;
	// 		if (t1==t2) {
	// 			ans++;
	// 			rGone[y]=1;
	// 			cGone[x]=1;
	// 		}
	// 	}
	// }
	unordered_map<int,int> CV;
	for (int i=0; i<M; i++) {
		if (C[i]==-1) continue;
		int val=C[i]-i;
		CV[val]++;
	}
	for (int i=0; i<N; i++) {
		if (R[i]==-1) continue;
		int val=R[i]-i;
		if (CV[val]>0) {
			CV[val]--;
			ans++;
		}
	}
	cout << ans << endl;
}