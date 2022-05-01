#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<long long> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	long long mxE=0;
	for (long long i : V) mxE=max(i,mxE);
	
	int l=1, r=mxE;
	while (l+1<r) {
		int m1=(l+r)/2,m2=m1+1;
		long long v1=0,v2=0;
		for (int i : V) {
			v1+=abs(i-m1);
			v2+=abs(i-m2);
		}
		if (v1==v2) {
			cout << v1 << endl;
			return 0;
		}
		else if (v1<v2) {
			r=m1;
		}
		else {
			l=m2;
		}
	}
	long long v1=0,v2=0;
	for (int i : V) {
		v1+=abs(i-l);
		v2+=abs(i-r);
	}
	long long ans=min(v1,v2);
	cout << ans << endl;
}