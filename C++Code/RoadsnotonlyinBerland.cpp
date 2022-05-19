#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> dsu;

int root(int a) {
    return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

bool unite(int a, int b) {
    a=root(a); b=root(b);
    if (a==b) return 0;
    if (-dsu[a]>-dsu[b]) swap(a,b);
    dsu[b]+=dsu[a];
    dsu[a]=b;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    dsu=vector<int>(N+1,-1);
    stack<vector<int>> rem;
    for (int i=0; i<N-1; i++) {
        int a,b; cin>>a>>b;
        if (!unite(a,b)) {
            rem.push({a,b});
        }
    }
    vector<bool> has(N+1);
    vector<int> rts;
    for (int i=1; i<=N; i++) {
        int rt=root(i);
        if (!has[rt]) {
            has[rt]=1;
            rts.push_back(rt);
        }
    }
    if (rts.size()==1) cout << 0 << endl;
    else {
        cout << rts.size()-1 << endl;
        for (int i=1; i<rts.size(); i++) {
            int a=rem.top()[0], b=rem.top()[1], c=rts[i-1], d=rts[i];
            cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
            rem.pop();
        }
    }
}