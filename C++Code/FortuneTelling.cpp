#include <bits/stdc++.h>
using namespace std;

void solve() {

}

void printBin(int n) {
	stack<bool> s;
	while (n) {
		bool bit=(n&1==1);
		s.push(bit);
		n >>= 1;
	}
	while (!s.empty()) {
		bool top = s.top();
		s.pop();
		cout << top;
	}
	cout << endl;
}

int main() {
	
}