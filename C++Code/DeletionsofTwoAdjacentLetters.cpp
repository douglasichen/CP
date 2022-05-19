#include <bits/stdc++.h>
using namespace std;

bool solve(string A, string B, int start) {
    int begin=-1;
    bool gd=0;
    for (char c : B) {
        for (int i=start; i<A.size(); i++) {
            if (A[i]==c) {
                gd=1;
                start=i+1;
                if (begin==-1) begin=i;
                break;
            }
        }
        if (!gd) return 0;
    }
    // cout << "b: " << begin << endl;
    if (begin%2!=0 || (A.size()-(begin+B.size()))%2!=0) return solve(A,B,start);
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin>>T;
    bool ans[T];
    for (int i=0; i<T; i++) {
        string A,B; cin>>A>>B;
        ans[i]=solve(A,B,0);
    }
    for (bool i : ans) cout << (i ? "YES" : "NO") << endl;
}