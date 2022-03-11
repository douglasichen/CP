#include <bits/stdc++.h>
using namespace std;

int Q, ans[500000][2], qs[500000][2], nextDp[100001];
unordered_map<int,int> prime2Ind;
vector<int> primes;

const int NUM_PS=21221, MAX_LOG=14;
long long sums[NUM_PS][MAX_LOG];

bool prime(int n) {
	int mx=sqrt(n);
	for (int i=2; i<=mx; i+=(i==2 ? 1 : 2)) {
		if (n%i==0) return 0;
	}
	return 1;
}

int nextPrime(int x) {
	// if already computed then relay data
	if (nextDp[x]) return nextDp[x];

	// compute
	int nx=x;
	if (nx%2==0 && nx!=2) nx++;
	while (!prime(nx)) {
		nx+=2;
	}
	int index=prime2Ind[nx];
	nextDp[x]=index;
	return index;
}

int getSum(int a, int b) {
	int size=b-a+1;
	int bin=size;

	long long ans=0;
	int e=0, i=a;

	while (bin) {
		if ((bin&1)==1) {
			ans+=sums[i][e];
			int parseSize=(1<<e);
			i+=parseSize;
		}
		
		
		bin>>=1;
		e++;
	}
	return ans;
}

void solve() {
	for (int i=0; i<Q; i++) {
		int x=qs[i][0], k=qs[i][1];
		int startInd=nextPrime(x), endInd=startInd+k-1;
		ans[i][0]=primes[endInd];
		ans[i][1]=getSum(startInd,endInd);
	}
}

void preComp() {
	// init primes
	for (int i=2; i<240000; i++) {
		if (prime(i)) {
			primes.push_back(i);
			prime2Ind[i]=primes.size()-1;
		}
	}

	// precompute sums with sparseTable
	for (int i=0; i<NUM_PS; i++) {
		sums[i][0]=primes[i];
	}

	for (int e=1; e<MAX_LOG; e++) {
		int size=(1<<e), smSize=(1<<(e-1)), maxI=NUM_PS-size;

		for (int i1=0; i1<=maxI; i1++) {
			int i2=i1+smSize;
			sums[i1][e]=sums[i1][e-1]+sums[i2][e-1];
		}
	}
}

int main() {
	cin>>Q;

	for (int i=0; i<Q; i++) {
		int x,k; cin>>x>>k;
		qs[i][0]=x; qs[i][1]=k;
	}
	preComp();
	solve();

	for (int i=0; i<Q; i++)
		cout << ans[i][0] << ' ' << ans[i][1] << endl;
}