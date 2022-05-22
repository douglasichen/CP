#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	// precompute primes
	vector<ll> primes;
	vector<bool> np(1e6+1);
	for (int i=2; i<=1e6; i++) {
		if (!np[i]) {
			primes.push_back(i);
			int a=i+i;
			while (a<=1e6) {
				np[a]=1;
				a+=i;
			}
		}
	}

	int N; cin>>N;
	vector<int> facs(1e6+1),V(N);
	for (int i=0; i<N; i++) {
		ll X;
		cin>>X; V[i]=X;
		for (ll p : primes) {
			if (p*p>X) break;
			while (X%p==0) X/=p, facs[p]++;
		}
		if (X>1) facs[X]++;
	}

	int A=1,B=0;
	for (int i=2; i<facs.size(); i++) {
		facs[i]/=N;
		if (facs[i]) {
			A*=pow(i,facs[i]);
		}
	}
	

	for (int i=0; i<N; i++) {
		ll X;
		X=V[i];
		vector<int> f(1e6+1);
		for (ll p : primes) {
			if (p*p>X) break;
			while (X%p==0) X/=p, f[p]++;
		}
		if (X>1) f[X]++;
		for (ll p : primes) {
			if (f[p]<facs[p]) {
				B+=facs[p]-f[p];
			}
		}
	}

	cout << A << ' ' << B << endl;


}