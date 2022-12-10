#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll md=100000021909, p=29;
	string A,B; cin>>A>>B;
	for (char &c : A) c-='A'-1;
	for (char &c : B) c-='A'-1;

	int M=A.size(), N=B.size(), ans=0;

	// init P
	vector<ll> P(N); P[0]=1;
	for (int i=1; i<N; i++) P[i]=P[i-1]*p%md;

	// init map
	map<ll,bool> has;
	ll h=0, h2=0;
	for (int i=0; i<N; i++) h=(h+B[i]*P[N-i-1])%md;
	for (int i=0; i<N; i++) {
		has[h]=1;
		h=((h-B[i]*P[N-1])%md+md)%md;
		h=h*p%md;
		h=(h+B[i])%md;
	}
	h=0;

	if (M>=N) {
		// init A hash
		for (int i=0; i<N; i++) h=(h+A[i]*P[N-i-1])%md;
		if (has[h]) ans=1;
		for (int a=0, b=N; b<M && !ans; a++, b++) {
			h=((h-A[a]*P[N-1])%md+md)%md;
			h=h*p%md;
			h=(h+A[b])%md;
			if (has[h]) ans=1;
		}
	}
	cout << (ans ? "yes" : "no") << endl;
}