#include <bits/stdc++.h>
using namespace std;

int N,K;
vector<long long> primes;
vector<int> has(1e6+1);
vector<vector<int>> F;

void f(long long a, int b, vector<pair<int,int>> M) {
	for (int o=0; o<has[a]; o++) {
		for (pair<int,int> p : M) F[p.first].push_back(p.second);
	}
	for (int i=b; i<primes.size(); i++) {
		long long prod=a*primes[i];
		if (prod>1e6) break;
		
		if (i==b) M.back().second++;
		else M.push_back(make_pair(i,1));
		
		f(prod,i,M);
		
		if (i==b) M.back().second--;
		else M.pop_back();
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	vector<bool> isPrime(1e6+1,1);
	for (int i=2; i<=1e6; i++) {
		if (!isPrime[i]) continue;
		primes.push_back(i);
		int a=i;
		while (a+i<=1e6) {
			a+=i;
			isPrime[a]=0;
		}
	}

	cin>>N>>K;
	F=vector<vector<int>>(primes.size());
	for (int i=0,inp; i<N; i++) cin>>inp,has[inp]++;

	vector<pair<int,int>> M;
	for (int i=0; i<primes.size(); i++) {
		M.push_back(make_pair(i,1));
		f(primes[i],i,M);
		M.pop_back();
	}

	long long ans=0;
	for (vector<int> V : F) {
		if (V.size()>=K) {
			long long sm=0;
			for (int i=V.size()-1; i>=K; i--) sm+=V[i];
			long long add=LLONG_MAX;
			for (int i=K-1; i>=0; i--) {
				sm+=V[i];
				add=min(add,sm/(K-i));
			}
			ans+=add;
		}
	}
    cout << ans << endl;
}