#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	if (N<4) {
		cout << 0 << endl;
		return 0;
	}
	else if (N==4) {
		cout << 1 << endl;
		return 0;
	}
	long long ans=5,add=10;
	for (int i=6; i<=N; i++) {
		ans+=add;
		add*=2;
	}
	cout << ans << endl;
}