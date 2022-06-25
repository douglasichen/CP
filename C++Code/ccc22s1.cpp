#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin>>N;
    int a=N/5, cnt=0;
    for (int i=a; i>=0; i--) {
        int left=N-i*5;
        if (left%4==0) cnt++;
    }
    cout << cnt << endl;
}