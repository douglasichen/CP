#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	long long N,ans=0; cin>>N;
	for (int i=2; i<N-1; i++) {
		ans+=(i-1)*(N-i-1);
	}
	ans*=N;
	ans/=4;
	cout << ans << endl;
}