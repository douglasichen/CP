#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int gcd(int a, int b) {
    while (b)
        a%=b,
        swap(a,b);
    return a;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

    int N;
    long long K; cin>>N>>K;
    vector<int> V(N);
    for (int &i : V) cin>>i, i--;
    
    vector<bool> vis(N);
    int a=1;
    for (int i=0; i<N; i++) {
        if (vis[i]) continue;
        vis[i]=1;
        int at=V[i], cnt=0;
        while (at!=i) vis[at]=1, at=V[at], cnt++;
        a=gcd(a,cnt);
    }
    K%=a;
    
    
}