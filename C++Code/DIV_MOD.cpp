#include <bits/stdc++.h>
using namespace std;

int f(int x, int a) {
    return x/3 + x%a;
}

int solve(int l, int r, int a) {
    if (r<a) return f(r,a);
    else if (r==a) return f(r-1,a);
    else {
        int m=r/a;
        int best=a*m-1;
        if (best<l) return f(r,a);
        else return f(best,a);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin>>T;
    int ans[T];
    for (int i=0; i<T; i++) {
        int l,r,a; cin>>l>>r>>a;
        ans[i]=solve(l,r,a);
    }
    for (int i : ans) {
        cout << i << endl;
    }
}