#include <bits/stdc++.h>
using namespace std;

const int MAX_N=100000, MAX_LOG=17;
int N,Q,V[MAX_N],ANS[10000],M[MAX_N][MAX_LOG+1],LOGS[MAX_N+1];

int main() {
    LOGS[1]=0;
    // for (int i=2; i<=MAX_N; i++) {
    //     LOGS[i]=LOGS[i/2]+1;
    //     // LOGS[i]=log(i);
    // }
    int p=1;
    for (int i=2; i<=MAX_N; i++) {
        if ((a<<(p+1))<=i) p++;
        LOGS[i]=p;
    }

    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>V[i];
        M[i][0]=V[i];
    }
    int mLog=LOGS[N];
    for (int e=1; e<=mLog; e++) {
        int e2=e-1, len=(1<<e), len2=(1<<e2), maxI=N-len;
        for (int i=0; i<=maxI; i++) {
            int i2=i+len2;
            M[i][e]=min(M[i][e2],M[i2][e2]);
        }
    }

    cin>>Q;
    for (int i=0; i<Q; i++) {
        int a,b; cin>>a>>b; if (a>b) swap(a,b);
        int len=b-a+1, e=LOGS[len], len2=(1<<e), c=b-len2+1;
        ANS[i]=min(M[a][e],M[c][e]);
    }
    for (int i=0; i<Q; i++) {
        cout << ANS[i] << endl;
    }
}