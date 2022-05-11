#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	while (b) {
		a%=b;
		swap(a,b);
	}
	return a;
}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<long long> P(N+1);
	long long inp;
	for (int i=2; i<=N; i++) {
		cout << "? " << 1 << " " << i << '\n';
		cout << flush;
		cin>>inp;
		P[i]=inp;
	}
	long long A=gcd(P[1],P[2]);
	for (int i=3; i<=N; i++) A=gcd(A,P[i]);
	cout << "! " << A;
	for (int i=2; i<=N; i++) {
		cout << ' ' << P[i]/A;
	}
	cout << endl;
	
}