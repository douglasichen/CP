#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	ll A=0,B=0,C=0;
	vector<ll> V(N);
	for (int i=0; i<N; i++) {
		cin>>V[i];
		C+=V[i];
	}
	B=C;
	ll dif=LLONG_MAX;
	int at=0;
	for (; at<N; at++) {
		A+=V[at];
		ll nDif=abs(C-A-A);
		if (nDif<dif) dif=nDif,B=C-A;
		else {
			A-=V[at];
			at--;
			break;
		}
	}
	cout << dif;
	int frm=0;
	for (int i=1; i<N; i++) {
		if (i-1<=at || frm<=i-1) A-=V[i-1],B+=V[i-1],frm++;
		at++;
		dif=abs(A-B);
		for (; ; at++) {
			if (at==N) at=0;
			A+=V[at];
			ll nDif=abs(C-A-A);
			if (nDif>dif) {
				A-=V[at];
				at--;
				break;
			}
			else {
				dif=nDif;
				B=C-A;
			}
		}
		// cout << A << " " << B << endl;
		cout << " " << dif;
	}
	cout << endl;

}