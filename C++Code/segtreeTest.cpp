#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void modify(vector<long long> &tree, int pos, long long val) {
    int N=tree.size()/2;
    int dif=T[pos+N]-val;
    for (tree[pos+=N]=val; pos>1; pos>>=1) tree[pos>>1]+=dif;
}

long long query(vector<long long> &tree, int A, int B) {
    int N=tree.size()/2;
    B++;
    long long ans=0;
    A+=N; B+=N;
    for (; A<B; A>>=1, B>>=1) {
        if (A&1) ans+=tree[A++];
        if (B&1) ans+=tree[--B];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,Q; cin>>N>>Q;
    vector<long long> tree(2*N);
    for (int i=0; i<N; i++) cin>>tree[i+N];
    
    // building the tree: iterate from i=N-1 to i=1 and tree[i]=tree[i*2]+tree[i*2+1];
    for (int i=N-1; i>0; i--) tree[i]=tree[i*2]+tree[i*2+1];

    for (int i=0; i<Q; i++) {
        int x,a,b; cin>>x>>a>>b;
        if (x==1) modify(tree,a,b);
        else cout << query(tree,a-1,b-1) << endl;
    }

}