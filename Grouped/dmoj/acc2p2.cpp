#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	char c;
	int cnt=0;
	for (int y=0; y<N; y++) {
		int a=1;
		for (int x=0; x<N; x++) {
			cin>>c;
			c-='0';
			if (c) a=0;
		}
		cnt+=a;
	}
	cout << cnt-1 << endl;
}