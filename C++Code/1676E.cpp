#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

void solve() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    for (int i=0; i<T; i++) {
        int N,Q; cin>>N>>Q;
        vector<ll> V(N);
        for (int o=0; o<N; o++) cin>>V[o];
        sort(V.begin(),V.end(),greater<ll>());
        for (int o=1; o<N; o++) V[o]+=V[o-1];
        for (int o=0,a; o<Q; o++) {
            cin>>a;
            auto it=lower_bound(V.begin(),V.end(),a);
            if (it==V.end()) cout << -1 << endl;
            else cout << (it-V.begin())+1 << endl;
        }
    }
}