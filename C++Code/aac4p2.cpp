#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	while (b) {
		a%=b;
		swap(a,b);
	}
	return a;
}

long long calc(long long a, long long b) {
	return (a*b)/gcd(a,b);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	vector<long long> V(N),lcm(N,1e9+1);
	for (int i=0; i<N; i++) cin>>V[i];
	lcm[0]=V[0];
	for (int i=1; i<N; i++) {
		lcm[i]=calc(lcm[i-1],V[i]);
		if (lcm[i]>1e9) break;
	}
	long long t;
	for (int i=0; i<Q; i++) {
		cin>>t;
		int L=0,R=N-1,ans=0;
		if (t%lcm[R]==0) ans=-1;
		else {
			while (L+1<R) {
				int mid=(L+R)/2;
				if (t%lcm[mid]==0) L=mid;
				else R=mid;
			}
			while (R>0 && t%lcm[R-1]!=0) R--;
			ans=R+1;
		}
		cout << ans << endl;
	}
}