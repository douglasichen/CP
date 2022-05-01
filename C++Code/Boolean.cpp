#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s; getline(cin,s);
	int N=s.size();
	int a=0;
	bool b=0;
	for (int i=0; i<N; i++) {
		if (s[i]=='n') a++;
		else if (s[i]=='T') b=1;
	}
	if (b) {
		if (a%2==0) cout << "True" << endl;
		else cout << "False" << endl;
	}
	else {
		if (a%2==0) cout << "False" << endl;
		else cout << "True" << endl;
	}
}