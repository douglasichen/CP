#include <bits/stdc++.h>
using namespace std;

string bin(int n) {
	string s="";
	while (n) {
		s+=(n&1 ? "1" : "0");
		n>>=1;
	}
	for (int i=0; i<s.size()/2; i++) {
		swap(s[i],s[s.size()-1-i]);
	}
	return s;
}

int main() {
	string a[26][4];
	for (int i=1; i<=25; i++) {
		for (int o=0; o<4; o++) {
			int n=o*25 + i;
			a[i][o]=bin(n);
			cout << a[i][o] << "\t" << n << "\t";
		}
		cout << endl;
	}	
}