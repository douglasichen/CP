#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N,H,P; cin>>N>>H>>P;
	vector<int> A(N);
	int mx=0;
	for (int i=0; i<N; i++) {
		cin>>A[i];
		mx=max(A[i],mx);
	}
	int cnt=0;
	for (int i : A) cnt+=(i==mx);
	
	int ans=0;
	int t=0;
	if (cnt==1) {
		for (int i : A) {
			int dif=i-t;
			if (i!=mx) {
				if (dif>0) t+=(dif*P);
			}
			else {
				
			}
		}
	}
	cout << ans << endl;
}