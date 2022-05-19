#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int P; cin>>P;
    for (int o=2; o*o<P; o++) {
        int at=1;
        while (P%o==0) {
            at*=o;
            ans[V[ind]]+=F[at];
            P/=o;
        }
    }
    if (P>1) ans[V[ind]]+=F[P];
}