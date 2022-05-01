#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	for (int i=0; i<T; i++) {
		int ans=0;
		int a,b; cin>>a>>b;
		int sm=a+b;
		if (sm%3==0) {
			if (min(a,b)*2>=max(a,b)) {
				ans=1;
			}
		}
		if (ans) cout << "YES";
		else cout << "NO";
		cout << endl;
	}	
}