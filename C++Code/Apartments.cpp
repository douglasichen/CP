#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M,K; cin>>N>>M>>K;
	vector<int> A(N),B(M); 
	for (int i=0; i<N; i++) cin>>A[i];
	for (int i=0; i<M; i++) cin>>B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	int ans=0;
	int a=0,b=0;
	while (a<N && b<M) {
		int dif=abs(A[a]-B[b]);
		if (dif<=K) {
			ans++; a++; b++;
		}
		else {
			if (A[a]<B[b]) a++;
			else b++;
		}
	}
	cout << ans << endl;
}