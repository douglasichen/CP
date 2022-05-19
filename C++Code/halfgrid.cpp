#include <bits/stdc++.h>
using namespace std;

unsigned long long md=1e9+7;

long long mult(int a, int b) {
    long long ans=1;
    for (int i=a; i<=b; i++) ans*=i,ans%=md;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int W,H,X; cin>>W>>H>>X;
    long long ans=(W==1 || H==1 ? 1 : mult(W,W+H-2)/mult(2,H-1));
    ans%=md;
    // for (int i=0,x,y; i<X; i++) {
    //     cin>>x>>y;
    //     ans-=fac(x+y-2)/(fac(x-1)*fac(y-1))*(fac(W-x+H-y)/(fac(W-x)*fac(H-y)));
    // }
    cout << ans << endl;
}