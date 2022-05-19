#include <bits/stdc++.h>
using namespace std;

vector<int> V,A;

bool cmp(int a, int b) {
    return A[a]>A[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,K; cin>>N>>K;
    V=vector<int>(N);
    vector<int> F(1e6+1),ans(1e6+1),inds;
    for (int i=0; i<N; i++) {
        cin>>V[i];
        if (!F[V[i]]) {
            inds.push_back(A.size());
            A.push_back(V[i]);
        }
        F[V[i]]++;
    }
    sort(inds.begin(),inds.end(),cmp);
    for (int i=0; i<inds.size(); i++) {
        int ind=inds[i];
        if (A[ind]==K) ans[A[ind]]+=i;
        else if (A[ind]>K) {
            int P=A[ind]-K;
            // cout << "P=" << P << endl;
            for (int o=1; o*o<=P; o++) {
                if (P%o==0) {
                    if (A[ind]%o || !K) ans[A[ind]]+=F[o];
                    int div=P/o;
                    if (o!=div) {
                        if (A[ind]%div || !K) ans[A[ind]]+=F[div];
                    }
                }
            }
        }
    }
    for (int i : V) cout << ans[i] << ' ';
    cout << endl;
    
}