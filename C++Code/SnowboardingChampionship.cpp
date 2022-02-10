#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int n,ha,hb; cin>>n>>ha>>hb;
	long long at=0,bt=0;
	for (int i=0; i<n; i++) {
		int a,b; cin>>a>>b;
		if (a<ha) at++;
		else at+=2;
		if (b<hb) bt++;
		else bt+=2;
		// cout << "at: " << at << endl;
		// cout << "bt: " << bt << endl;
	}
	string ans="";
	if (at==bt) ans="Tie!";
	else if (at>bt) ans="Tommy wins!";
	else ans="Andrew wins!";
	cout << ans << endl;
}
	
