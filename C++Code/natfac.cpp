#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	unsigned long long N; cin>>N;
	unsigned long long sm=0;
	for (unsigned long long i=1; i<N; i++) {
		if (N%i==0) sm+=i;
	}
	bool ans=sm==N;
	cout << ans << endl;
}