#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int d; cin>>d;
	string s; cin>>s;
	for (int i=0; i<s.size()-1; i++) {
		int a=s[i]-'0', b=s[i+1]-'0';
		if (b>a) {
			swap(s[i],s[i+1]);
			break;
		}
	}
	cout << s << endl;
}