#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N; cin>>N;
	long long V[N];
	for (int i=0; i<N; i++) cin>>V[i];
	long long F,X; cin>>X>>F;

	long long t=0;
	for (long long i : V) {
		if (i<=X) continue;
		if (i-F<=0) continue;

		long long k=X;
		if (k+F>i) k=i-F;
		
		long long need=k+F;
		long long r=i%need;
		t+=(i/need);
		
		// extra
		if (r>X && r-F-1>=0) t++;
		
		// cout << t << endl;
	}

	long long ans=t*F;
	cout << ans << endl;
}