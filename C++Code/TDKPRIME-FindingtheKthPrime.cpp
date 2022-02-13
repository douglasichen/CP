#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
	for (int i=2; i<=sqrt(n); i++) {
		if (n==i) continue;
		if (n%i==0)
			return 0;
	}
	return 1;
}

int main() {
	int t; cin>>t;
	int mx=1;
	vector<int> ns(t);
	for (int i=0; i<t; i++) {
		int n; cin>>n;
		ns[i]=n;
		mx=max(mx,n);
	}
	vector<int> primes;
	primes.push_back(0);
	for (int i=2; primes.size()<=mx; i+=(i==2 ? 1 : 2)) {
		if (prime(i))
			primes.push_back(i);
	}

	for (int i : ns) {
		cout << primes[i] << endl;
	}
}