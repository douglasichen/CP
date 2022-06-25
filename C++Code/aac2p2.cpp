#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin>>N;
    vector<long long> V(N);
    map<int,bool> mp;
    for (int i=0; i<N; i++) cin>>V[i], mp[V[i]]=1;
    for (int i=0; i<N-1; i++) {
        for (int o=i+1; o<N; o++) {
            long long sm=V[i]+V[o];
            if (sm%2==0 && mp[sm/2]) {
                cout << 3 << endl;
                return 0;
            }
        }
    }
    if (N==2 && (V[0]+V[1])%2) cout << 1 << endl;
    else cout << 2 << endl;
}