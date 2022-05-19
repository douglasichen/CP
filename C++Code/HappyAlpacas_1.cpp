#include <bits/stdc++.h>
using namespace std;

int N,X,V[1000000];

bool solve() {
    if (X==N-1) return -1;

    int h=0;
    V[0]=0;
    for (int i=0; i<N-1; i++) {
        if (h<X) {
            V[i+1]=V[i];
            h++;
        }
        else {
            V[i+1]=!V[i];
        }
    }
    if (V[N-1]==V[0]) h++;
    return h==X;
}

int main() {
    cin>>N>>X;

    bool good=solve();
    if (good) {
        for (int i=0; i<N; i++)
            cout << V[i] << (i<N-1?" ":"");
        cout << endl;
    }
    else cout << -1 << endl;
}