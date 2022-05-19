#include <bits/stdc++.h>
using namespace std;

vector<long long> D;

bool sorter(int &a, int &b) {
    return D[a]>D[b];
}

long long solve(int &N, int &M, vector<vector<vector<int>>> &G, int &A, int &B) {
    priority_queue<int, vector<int>, decltype(&sorter)> pq(sorter); // node
    pq.push(A);
    D[A]=0;
    while (!pq.empty()) {
        break;
    }
    return D[B];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    long long ans[T];
    for (int i=0; i<T; i++) {
        int N,M; cin>>N>>M;
        D=vector<long long>(N+1,LLONG_MAX);
        vector<vector<vector<int>>> G(N+1);
        for (int o=0; o<M; o++) {
            int a,b,c; cin>>a>>b>>c;
            G[a].push_back({b,c});
            G[b].push_back({a,c});
        }
        int A,B; cin>>A>>B;
        ans[i]=solve(N,M,G,A,B);
    }
    for (long long i : ans) {
        if (i==LLONG_MAX) cout << "NO" << endl;
        else cout << i << endl;
    }
}