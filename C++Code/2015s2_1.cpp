#include <bits/stdc++.h>
using namespace std;




int S=0,M=0,L=0;

void solve() {

}

int main() {
	int j,a; cin>>j>>a;
	vector<int> jv(j+1);
	for (int i=1; i<=j; i++) {
		char inp; cin>>inp;
		int size=1;
		if (inp=='M') size=2;
		else if (inp=='L') size=3;
		jv[i]=size;
	}

	vector<bool> taken(1e6+1);
	int ans=0;
	for (int i=1; i<=a; i++) {
		char c; int k; cin>>c>>k;
		int size=1;
		if (c=='M') size=2;
		else if (c=='L') size=3;
		if (!taken[k]) {
			if (jv[k] >= size) {
				taken[k]=true;
				ans++;
			}
		}
	}
	cout << ans << endl;

}