#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
	for (int i=2; i<=sqrt(n); i++) {
		if (n%i==0) return false;
	}
	return true;
}

int solve(int n) {
	int ans=0;
	for (int i=2; i<=n; i++) {
		if (prime(i)) ans++;
	}
	return ans;
}

int main() {
	int n; cin>>n;

	int a = (float)n/(float)(log((float)n));
	int b = solve(n);

	cout << a << ' ' << b << endl;
}