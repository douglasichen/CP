#include <bits/stdc++.h>
using namespace std;

int solve(int n, string s) {
    int a=0;
    a+=s.front()=='W'+s.back()=='W';
    
    return a;
}

int main() {
    int t; cin>>t;
    int ans[1000];
    for (int i=0; i<t; i++) {
        int n; cin>>n;
        string s; cin>>s;
        ans[i]=solve(n,s);
    }
    for (int i=0; i<t; i++) {
        cout << ans[i] << endl;
    }
}