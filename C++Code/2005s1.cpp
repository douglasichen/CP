#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

char fix (char c) {
	char n = '9';
	if (c<='C') n='2';
	else if (c<='F') n='3';
	else if (c<='I') n='4';
	else if (c<='L') n='5';
	else if (c<='O') n='6';
	else if (c<='S') n='7';
	else if (c<='V') n='8';
	else if (c<='Z') n='9';
	return n;
}

string filter (string s) {
	string ss = "";
	for (int i=0; i<s.length(); i++) {
		if (s[i] == '-') continue;
		char c = s[i];
		char t = c;
		if (c>='A' && c<='Z') c = fix(c);
		ss+=c;
	}
	string ns = "";
	for (int i=0; i<10; i++) {
		ns+=ss[i];
		if (i==2 || i==5) ns+='-';
	}
	return ns;
}

int main() {
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		string inp; cin>>inp;
		inp = filter(inp);
		cout<<inp<<endl;
	}
}