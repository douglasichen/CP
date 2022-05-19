#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
    int N,K,V[1000001]; cin>>N>>K;
    for (int i=0; i<N; i++) cin>>V[i];
    unordered_map<int,int> cnt;

    long long ans=0;
    N-K+2;
    for (int i=0; i<N; i++) {
        int dc=0;
        for (int o=i; o<N; o++) {
            if (cnt[V[o]]==0) dc++;
            cnt[V[o]]++;
            if (dc==K) ans++;
            if (dc>K) break;
        }
        cnt.clear();
    }
    cout << ans << endl;

}