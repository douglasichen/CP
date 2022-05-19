#include <bits/stdc++.h>
using namespace std;

int N,Q;
vector<int> v;

// vector<vector<unordered_map<int>>> haves;

bool solve(int l, int r, int x) {
    l--; r--;
    unordered_map<int,bool> needed;
    for (int i=l; i<=r; i++) {
        int e=v[i];
        if (needed[e]) return 1;
        if (x%e==0) {
            int need=x/e;
            if (need!=e) {
                needed[need]=1;
                // if (have[need]) return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin>>N>>Q;
    v=*(new vector<int>(N));
    for (int i=0; i<N; i++) {
        cin>>v[i];
    }
    bool ans[Q];
    for (int i=0; i<Q; i++) {
        int l,r,x; cin>>l>>r>>x;
        ans[i]=solve(l,r,x);
    }
    for (bool i : ans) cout << (i ? "YES" : "NO") << endl;
}