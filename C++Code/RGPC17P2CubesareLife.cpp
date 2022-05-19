#include <bits/stdc++.h>
using namespace std;

const int MX_LOG=19, MX_N=1000000;
int LOGS[MX_N+1];

unsigned long long N,M,Q,V[MX_N], ST[MX_N][MX_LOG+1];
const vector<int> u={INT_MAX,0};

bitset<1000001> init;
unordered_map<unsigned long long,vector<int>> minMax;

unsigned long long sumUp(int i, int j) {   
    unsigned long long sum=0;
    int sz=j-i+1;
    if (sz<0) return 0;
    int e=0;
    while (sz) {
        if (sz&1) {
            sum+=ST[i][e];
        }
        sz>>=1;
        e++;
    }
    return sum;
}

bool solve(int A, int B) {
    int i=minMax[A][0], j=minMax[B][1];
    unsigned long long sum=sumUp(i,j);
    return sum>=(unsigned long long)M;
}

void precomp() {
    LOGS[1]=0;
    int k=1;
    for (int i=2; i<=MX_N; i++) {
        if (1<<(k+1)<=i) k++;
        LOGS[i]=k;
    }

    // sparse
    int mxE=LOGS[N];
    for (int e=1; e<=mxE; e++) {
        int sz=1<<e, e2=e-1, half=1<<e2, mxI=N-sz;
        for (int i=0; i<=mxI; i++) {
            int i2=i+half;
            ST[i][e]=ST[i][e2]+ST[i2][e2];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N>>M>>Q;
    bool ans[Q];
    for (int i=0; i<N; i++) {
        cin>>V[i];
        ST[i][0]=V[i];
        if (!init[V[i]]) {
            minMax[V[i]]={i,i};
            init[V[i]]=1;
        }
        else minMax[V[i]]={min(minMax[V[i]][0],i), max(minMax[V[i]][1],i)};
    }
    precomp();
    for (int i=0; i<Q; i++) {
        int a,b; cin>>a>>b;
        ans[i]=solve(a,b);
    }
    for (bool i : ans) cout << (i ? "Enough" : "Not enough") << endl;
    
}