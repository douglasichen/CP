#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool palindrome(vector<int> V) {
    for (int i=0; i<V.size()/2; i++) {
        if (V[i]!=V[int(V.size())-i-1])
            return 0;
    }
    return 1;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    map<char, int> M;
    for (char c='0'; c<='9'; c++) M[c]=c-'0';
    for (char c='A'; c<='Z'; c++) M[c]=c-'A'+10;

    int N,ans=0; cin>>N;
    string S; cin>>S;
    int carry=0;
    vector<int> A,B;
    for (char c : S) A.push_back(M[c]);
    while (!palindrome(A)) {
        int sz=A.size();
        for (int i=0; i<sz; i++) {
            int a=A[i], b=A[sz-i-1];
            int sm=a+b+carry;
            B.push_back(sm%N);
            carry=sm/N;
        }
        if (carry) {
            B.push_back(carry);
            carry=0;
        }
        swap(A,B);
        // for (int i : A) cout << i << ' ';
        // cout << endl;
        B.clear();
        ans++;
        if (ans==30) break;
    }
    if (palindrome(A)) cout << "STEP=" << ans << endl;
    else cout << "Impossible!" << endl;
}
