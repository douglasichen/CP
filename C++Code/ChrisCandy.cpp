#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long K; cin>>K;
    if ((K+1)%2!=0) cout << "Sad Chris";
    else {
        if (K==1) {
            cout << 1 << endl << 1 << endl;
            return 0;
        }
        long long N=ceil((float)(K+1)/2.0);
        if (2*N-1>1e5) cout << "Sad Chris";
        else {
            cout << N << endl;
            cout << 1 << ' ';
            for (int i=0; i<N-1; i++) {
                if (i!=N-2) {
                    cout << 2 << ' ';
                }
                else cout << 2;
            }
        }
    }
}