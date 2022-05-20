#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	for (int i=0; i<T; i++) {
		int N; cin>>N;
		int a=0,b=0;
		bool gd=1;
		for (int o=0,inp; o<N; o++) {
			cin>>inp;
			if (inp%2) {
				if (inp<a) {
					gd=0;
				}
				a=inp;
			}
			else {
				if (inp<b) {
					gd=0;
				}
				b=inp;
			}
		}
		if (gd) cout << "YES" << endl;
		else cout << "NO" << endl;

	}	
}