#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long a=0;
    for (unsigned long long i=1; i<=100; i++) {
        a+=i*powl(3LL,i);
        unsigned long long b=3LL*((2LL*i-1LL) * powl(3LL,i) + 1LL)/4;
        if (a!=b) cout << 1 << endl;
    }  
}