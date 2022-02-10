#include<bits/stdc++.h>
using namespace std;

string toBin(int n) {
    stack<bool> s;
    while (n) {
        s.push((n&1)==1);
        n >>= 1;
    }
    string str="";
    while (!s.empty()) {
        str+=(s.top() ? "1" : "0");
        s.pop();
    }
    return str;
}

int main() {
    cout << toBin(1000) << endl;
}