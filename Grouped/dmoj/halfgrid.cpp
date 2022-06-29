#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ull unsigned long long

ull md=1e9+7;
// ull fpw(ull a, ull b) {
// 	ull ans=1;
// 	for (ull p=a; b; b>>=1, p*=p, p%=md) {
// 		if (b&1) ans*=p, ans%=md;
// 	}
// 	return ans;
// }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int W,H,X; cin>>W>>H>>X; W--, H--;
	for (int i=0,a,b; i<X; i++) cin>>a>>b;
	if (W==0 || H==0) {
		cout << 1 << endl;
		return 0;
	}

	vector<bool> isP(2e6,1);
	
	vector<long long> fW(2e6), fH(2e6), fWH(2e6);
	for (int i=2; i<2e6; i++) {
		if (!isP[i]) continue;
		for (int at=i, cnt=1; at<2e6; at+=i, cnt++) {
			if (at!=i) isP[at]=0;
			if (at<=W) fW[i]+=cnt;
			if (at<=H) fH[i]+=cnt;
			if (at<=H+W) fWH[i]+=cnt;
		}
	}

	
	for (int i=2; i<2e6; i++) fWH[i]-=fW[i]+fH[i];

	ull ans=1;
	for (int a=2; a<2e6; a++) {
		for (int i=0; i<fWH[a]; i++) ans*=a, ans%=md;
	}
	cout << ans << endl;
	

}