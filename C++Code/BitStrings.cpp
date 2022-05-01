#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	unsigned long long N; cin>>N;
	unsigned long long md=1e9+7;
	unsigned long long ans=1;
	for (unsigned int i=0; i<N; i++) {
		ans*=2;
		ans%=md;
	}
	cout << ans << endl;
}