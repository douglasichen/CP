#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int g,p; cin>>g>>p;
	// vector<bool> taken(g+1);
	vector<int> pv(p);
	for (int i=0; i<p; i++) {
		cin >> pv[i];
	}

	int ans=0;
	vector<int> taken(g+1);
	for (int gPos : pv) {
		for (int i=gPos; i>=0; i--) {
			gPos = i;
			if (!taken[i]) break;
		}
		// cout << gPos << ' ';
		if (gPos==0) break;
		ans++;
		taken[gPos]=true;
	}
	cout << ans << endl;
}