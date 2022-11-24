#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int md=1e9+7;
int mx=2e6;
vector<int> spf(mx+1);

long long mult,res;
int fpow(int a, int b) {
	mult=a, res=1;
	while (b) {
		if (b&1) res*=mult, res%=md;
		mult*=mult, mult%=md;
		b>>=1;
	}
	return res;
}

long long ways(int W, int H) {
	if (W>H) swap(W,H);
	int Z=W+H;
	vector<int> F(Z+1);
	for (int i=H+1,at; i<=Z; i++) {
		at=i;
		while (at) {
			if (spf[at]!=0) F[spf[at]]++, at/=spf[at];
			else F[at]++, at=0;
		}
	}
	for (int i=2, at; i<=W; i++) {
		at=i;
		while (at) {
			if (spf[at]!=0) F[spf[at]]--, at/=spf[at];
			else F[at]--, at=0;
		}
	}
	
	long long ans=1;
	for (int i=2; i<=Z; i++)
		ans*=fpow(i,F[i]), ans%=md;
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i=2,at; i<=mx; i++) {
		at=i;
		while (at+i<=mx) {
			at+=i;
			if (!spf[at]) spf[at]=i;
		}
	}
	
	int W,H,X,Z; cin>>W>>H>>X;
	long long ans=ways(W-1, H-1);
	int a,b,c,d;
	if (X==1) {
		cin>>a>>b;
		ans-=ways(a-1,b-1)*ways(W-a, H-b)%md;
	}
	else if (X==2) {
		cin>>a>>b>>c>>d;
		if (a>c) swap(a,c), swap(b,d);
		ans-=ways(a-1,b-1)*ways(W-a, H-b)%md,
		ans-=ways(b-1,d-1)*ways(W-b, H-d)%md;
		if (b>=d) 
			ans-=ways(a-1,b-1)
			*ways(c-a, d-b)%md
			*ways(W-c, H-d)%md;
	}
	ans%=md;
	while (ans<0) ans+=md;
	
	cout << ans << endl;
}
