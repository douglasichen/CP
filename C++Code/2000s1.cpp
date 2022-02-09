#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int q; cin>>q;
	int a,b,c; cin>>a>>b>>c;

	int ans=0;
	
	while (q>0) {
		a++;
		q--;
		if (a%35==0) q+=30;
		ans++;
		// cout << q << ' ';

		if (!q) break;
		
		b++;
		q--;
		if (b%100==0) q+=60;
		ans++;
		// cout << q << ' ';

		if (!q) break;

		c++;
		q--;
		if (c%10==0) q+=9;
		ans++;
		// cout << q << ' ';

		if (!q) break;


		// if (ans>10) break;
	}

	cout << "Martha plays " << ans << " times before going broke." << endl;
}