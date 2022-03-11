#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	bool ans[T];
	for (int i=0; i<T; i++) {
		string s; cin>>s;
		int r=0,g=0,b=0;
		bool ok=1;
		for (char c : s) {
			r+=(c=='r');
			g+=(c=='g');
			b+=(c=='b');
			r-=(c=='R');
			g-=(c=='G');
			b-=(c=='B');
			if (r<0 || g<0 || b<0) {
				ok=0;
				break;
			}
		}
		ans[i]=ok;
	}
	for (bool i : ans) cout << (i ? "YES" : "NO") << endl; 
}