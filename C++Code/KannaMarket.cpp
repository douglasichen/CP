#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long N,M,md=1e9+7;

ll fpw(ll a, ll b) {
	ll res=a,ans=1;
	while (b) {
		if (b&1) {
			ans*=res;
			ans%=md;
		}
		res*=res;
		res%=md;
		b>>=1;
	}
	return ans;
}

ll ways(vector<ll> Ts, ll P, ll B) {
    B=max(B,1LL);
    if (Ts.size()==0) return 0;
	vector<ll> sms(2*M+1);
    if (P) {
        for (int i=2; i<=M+1; i++) {
            sms[i]=fpw(i-1,P);
        }
        int j=M-1;
        for (int i=M+2; i<=2*M; i++) {
            sms[i]=fpw(j,P);
            j--;
        }
    }
	ll ans=0;
    if (P==0) {
        ans=B;
    }
    else {
        for (int i : Ts) {
            ans+=sms[i];
            ans%=md;
        }
    }
	return max(ans%md,1LL);
}

void fl(vector<int> &D, int &a, int &b, int &emp, int &hlf) {
    if (a&&b) {
        D[a+b]++;
        D[a+b+1]--;
    }
    else if (a||b) {
        hlf++;
        if (a<b) swap(a,b);
        D[a+1]++;
        D[a+M+1]--;
    }
    else {
        emp++;
        D[2]++;
        D[M*2+1]--;
    }
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    
    cin>>N>>M;
    vector<vector<int>> V(2,vector<int>(N));
    for (int y=0; y<2; y++) for (int x=0; x<N; x++) cin>>V[y][x];
	vector<int> dA(M*2+2),dB(M*2+2);
	int even=0,odd=0,empEven=0,hlfEven=0,empOdd=0,hlfOdd=0;
	for (int x=0,a,b; x<N; x++) {
        a=V[0][x]; b=V[1][x];
		if (x%2==0) {
			even++;
            fl(dA,a,b,empEven,hlfEven);
		}
		else {
			odd++;
			fl(dB,a,b,empOdd,hlfOdd);
		}
	}
	vector<long long> tsA,tsB;
	for (int i=2; i<dA.size(); i++) {
		dA[i]+=dA[i-1];
		dB[i]+=dB[i-1];
		if (dA[i]==even) tsA.push_back(i);
		if (dB[i]==odd) tsB.push_back(i);
	}
    // for (int i : tsA) cout << i << ' '; cout << endl;
    // for (int i : tsB) cout << i << ' '; cout << endl;
    long long A=ways(tsA,empEven,hlfEven),B=ways(tsB,empOdd,hlfOdd);
    // cout << A << ' ' << B << endl;
	long long ans=A*B%md;
	cout << ans << endl;
}