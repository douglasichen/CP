#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll md=1e9+7, p=3, N,A,B,Q,L,R;
map<char,int> conv={{'R',0}, {'G',1}, {'B',2}};
char c;
ll P[1000000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    // init 
    P[0]=1;
    for (int i=1; i<1e6; i++) P[i]=P[i-1]*p%md;

    cin>>N;
    vector<vector<ll>> T(3, vector<ll>(N<<1));
    A=0;
    for (int i=0; i<N; i++) cin>>c, T[conv[c]][N+i]=P[i], A=(A+(conv[c]+1)*P[i]%md)%md;
    for (int o=0; o<3; o++)
        for (int i=N-1; i; i--) 
            T[o][i]=(T[o][i<<1] + T[o][i<<1|1])%md;
    
    B=0;
    for (int i=0; i<N; i++) cin>>c, B=(B+(conv[c]+1)*P[i]%md)%md;
    
    cout << A << ' ' << B << endl;
    if (A==B) {
        cout << 0 << endl;
        return 0;
    }

    cin>>Q;
    for (int q=1; q<=Q; q++) {
        cin>>L>>R; L--;
        // swap sums in interval l,r
        for (L+=N, R+=N; L<R; L>>=1, R>>=1) {
            if (L&1) {
                swap(T[2][L], T[1][L]);
                swap(T[1][L], T[0][L]);
                L++;
            }
            if (R&1) {
                R--;
                swap(T[2][R], T[1][R]);
                swap(T[1][R], T[0][R]);
            }
        }

        // get sum
        A=0;
        for (int i=0; i<3; i++) {
            L=0, R=N;
            for (L+=N, R+=N; L<R; L>>=1, R>>=1) {
                if (L&1) {
                    A=(A + (i+1)*T[i][L]%md)%md;
                    L++;
                }
                if (R&1) {
                    R--;
                    A=(A + (i+1)*T[i][R]%md)%md;
                }
            }
        }
        cout << A << ' ' << B << endl;
        
        // compare sum
        if (A==B) {
            cout << q << endl;
            return 0;
        }
    }
    cout << -1 << endl;


}
