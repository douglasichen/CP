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
	vector<long long> lcm(N,1e9+1);
	cin>>lcm[0];
	long long inp;
	bool bd=0;
	for (int i=1; i<N; i++) {
		cin>>inp;
		if (bd) continue;
		lcm[i]=calc(lcm[i-1],inp);
		if (lcm[i]>1e9) bd=1;
	}
	long long t;
	for (int i=0; i<Q; i++) {
		cin>>t;
		int L=0,R=N-1,ans=0;
		if (t%lcm[R]==0) ans=-1;
		else {
			while (L<=R) {
				int mid=(L+R)>>1;
				if (t%lcm[mid] || lcm[mid]>1e9) ans=mid+1,R=mid-1;
				else L=mid+1;
			}
		}
		cout << ans << '\n';
	}
}