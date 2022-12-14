#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int md=1e9+7, p=3, B=0,Q;
map<char,int> conv={{'R',0}, {'G',1}, {'B',2}};
char c;
int P[1000000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    // init
    P[0]=1;
    for (int i=1; i<1e6; i++) P[i]=P[i-1]*p%md;

    int N; cin>>N;
    vector<vector<int>> T(3, vector<int>(N<<1));
    for (int i=0; i<N; i++) cin>>c, T[conv[c]][N+i]=P[i];
    for (int i=0; i<N; i++) cin>>c, B=(B+(conv[c]+1)*P[i]%md)%md;
    cin>>Q;
    for (int q=1; q<=Q; q++) {
        bool gd=0;
        // swap sums


        // get sum

        
        // compare sum

        if (gd) {
            cout << q << endl;
            return 0;
        }
    }
    cout << -1 << endl;


}
