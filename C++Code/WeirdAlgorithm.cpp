#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	unsigned long long N; cin>>N;
	string ans="";
	ans += to_string(N);
	while (N!=1) {
		if (N%2LL==0LL) N/=2LL;
		else N=N*3LL+1LL;
		ans += " " + to_string(N);
	}
	cout << ans << endl;
}