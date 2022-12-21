#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin>>N;
    vector<ll> V(N), dis(N);
    for (int i=0; i<N; i++) cin>>V[i];
    ll M,P,S1,S2,A=0,B=0,nDif,x; cin>>M>>P>>S1>>S2; M--, P--;
    for (int i=0; i<N; i++) dis[i]=M-i;
    V[P]+=S1;
    for (int i=0; i<M; i++) A+=dis[i]*V[i];
    for (int i=M+1; i<N; i++) B+=dis[i]*V[i];
    ll dif=abs(A+B);
    pair<ll,int> ans={LLONG_MAX, 0};
    for (int i=0; i<N; i++) {
        x=S2*dis[i];
        nDif=abs(A+B+x);
        if (nDif<ans.first) ans={nDif, i+1};
    }
    cout << ans.second << endl;
}
