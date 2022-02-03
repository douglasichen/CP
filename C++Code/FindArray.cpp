#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef vector<vector<int>> vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(x,n) for(int x = 0; x < n; ++x)

#define printV(v) FOR(x,v.size()) cout<<v[x]<<' '; cout<<endl;


bool isPrime(int n) {
	for (int i=2; i<=sqrt(n); i++) {
		if (n%i==0) return false;
	}
	return true;
}

int main() {
	int t; cin>>t;
	vi primes;
	for (int i=2; primes.size()<1000; i++) {
		if (isPrime(i)) primes.PB(i);
	}
	FOR(i,t) {
		int n; cin>>n;
		FOR(i,n) cout << primes[i] << ' ';
		cout << endl;
	}
}