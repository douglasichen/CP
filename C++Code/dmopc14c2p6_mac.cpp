#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin>>N;
    vector<vector<int>> A,Q(20001);
    for (int i=0,inp; i<N; i++) {
        cin>>inp;
        A.push_back({inp,i});
    }
    for (int i=0,a,b,x; i<Q; i++) {
        cin>>a>>b>>x;
        Q[x].push_back({a,b,i});
    }

    sort(A.begin(),A.end());
    vector<int> T(20001);
    int at=N-1;
    set<int> B;
    for (int i=20000; i>0; i--) {
        while (at>=0 && A[at][0]>=i) B.emplace(V[at][1]),at--;
        for (vector<int> q : Q[i]) {
            int a=q[0], b=q[1], ind=q[2];
            int ans=0;
            auto lb=lower_bound(B.begin(),B.end(),a), lb2=lower_bound(B.begin(),B.end(),b);
            if (lb!=B.end() && lb2!=B.end() && (*lb)>=a && (*(--lb2))<=b) {

            }
            T[ind]=ans;
        }
    }
}