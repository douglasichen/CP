#include <bits/stdc++.h>
using namespace std;

long long solve(int n, int m, long long v[][2]) {
    long long best=1,mx=0,mn=0;
    for (int i=0; i<n; i++) {
        long long dif=v[i][1]-v[i][0];
        if (dif>0) best*=dif;

        mn+=v[i][0];
        mx+=v[i][0];
    }
    if (mn>m) return 0;
    if (mn==m) return 1;
    if (m>=mx) return best;
    
}

int main() {
    int t; cin>>t;
    long long ans[t];
    for (int i=0; i<t; i++) {
        int n,m; cin>>n>>m;
        long long v[n][2];
        for (int o=0; o<n; o++)
            cin>>v[o][0]>>v[o][1];
        ans[i]=solve(n,m,v);
    }
    for (long long i : ans) cout << i << endl;
}