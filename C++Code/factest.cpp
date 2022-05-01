#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N; cin>>N;
	for (int i=2; i*i<=N; i++) {
		while (N%i==0) {
			cout << i << ' ';
			N/=i;
		}
	}
	if (N>1) cout << N;
	cout << endl;
}