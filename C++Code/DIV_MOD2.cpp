#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin>>T;
    int ans[T];
    for (int i=0; i<T; i++) {
        int L,R,A; cin>>L>>R>>A;
        ans[i]=solve(L,R,A);
    }
    for (int i : ans) cout << i << endl;
}