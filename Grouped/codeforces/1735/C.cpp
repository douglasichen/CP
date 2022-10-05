#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while (T--) {
        int N; cin>>N;
        string S; cin>>S;
        char mn=*min_element(S.begin(), S.end());
        vector<int> dif(N,INT_MAX);
        int start;
        for (int i=0; i<N; i++) {
            if (S[i]==mn) {
                start=i;
                break;
            }
        }
        string ans="";
        for (int i=start; i<N+start; i++) ans+=S[i%N];
        int lastMn=start;
        for (int i=start+1; i<N+start; i++) {
            if (V[i%N]==mn) lastMn=i%N;
            if (V[i%N]<ans[i-start]) start=lastMn
        }
    }
}
