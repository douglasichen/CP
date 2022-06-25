#include <bits/stdc++.h>
using namespace std;

int N;
long long ans=0;
vector<long long> dp;

long long solve(int at) {
    if (at==N) return 1;
    // if (dp[at]!=-1) return dp[at];
    long long m=0;
    for (int i=1; at+i<=N; i++) {
        if (at+i*2<=N) m+=solve(at+i*2);
        else if (at+i==N) m+=solve(at+i);
    }
    // dp[at]=m;
    return m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    dp.assign(N*2,-1LL);
    ans=solve(0);
    cout << ans << endl;


}