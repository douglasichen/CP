#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int sq=sqrt(1e5);
	vector<bool> isPrime(sq+1,1);
	vector<int> primes;
	for (int i=2; i<=sq; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			int at=i;
			while (at+i<=sq) {
				at+=i;
				isPrime[at]=0;
			}
		}
	}

	int N,Q; cin>>N>>Q;
	vector<set<int>> V(1e5+1);
	for (int i=1,inp; i<=N; i++) {
		cin>>inp;
		V[inp].emplace(i);
	}
	for (int i=0,L,R,X,mx,ans; i<Q; i++) {
		cin>>L>>R>>X;
		ans=0;
		for (int a : primes) {
			if (a*a>=X) break;
			if (X%a==0) {
				int b=X/a;
				auto lbA=V[a].lower_bound(L), lbB=V[b].lower_bound(L);
				if (lbA!=V[a].end() && lbB!=V[b].end() && *lbA<=R && *lbB<=R) {
					ans=1;
					break;
				}
			}
		}
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}