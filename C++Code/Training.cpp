#include <bits/stdc++.h>
using namespace std;

int solve(int N, int P, vector<int> V) {
    sort(V.begin(), V.end(), greater<int>());
    int ans=0;
    for (int i=0; i<P; i++) ans+=(V[0]-V[i]);
    
    int maxI=N-P;
    int h=ans;
    for (int left=0; left<maxI; left++) {
        int right=left+P;
        int dif=V[left]-V[left+1];
        dif*=(P-1);
        h-=dif;
        h+=(V[left+1]-V[right]);
        ans=min(ans,h);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin>>T;
    int ans[T];
    for (int i=0; i<T; i++) {
        int N,P; cin>>N>>P;
        vector<int> V(N);
        for (int k=0; k<N; k++) cin>>V[k];
        ans[i]=solve(N,P,V);
    }
    for (int i=1; i<=T; i++) {
        cout << "Case #" << i << ": " << ans[i-1] << endl;
    }
}