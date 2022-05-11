#include <bits/stdc++.h>
using namespace std;

// unsigned long long fpw(unsigned long long a, unsigned long long b) {
// 	unsigned long long res=a, ans=1;
// 	while (b) {
// 		if (b&1) {
// 			if (ans>=1e18) return ans;
// 			ans*=res;
// 		}
// 		res*=res;
// 		b>>=1;
// 	}
// 	return ans;
// }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	unsigned long long N,M,K=0,P; cin>>N>>M;
	P=N;
	while (P>1) P/=2,K++;
	K/=M;
	while (powl(2,M*K)<N) K++;
	cout << K << endl;


}