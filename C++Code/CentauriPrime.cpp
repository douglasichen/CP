#include <bits/stdc++.h>
using namespace std;

unordered_map<char,bool> vow;

string solve(string s) {
	int own=0;
	if (vow[s.back()]) own=1;
	else if (s.back()!='Y' && s.back()!='y')
		own=2;

	if (own==0) {
		return s + " is ruled by nobody.";
	}
	else if (own==1) {
		return s + " is ruled by Alice.";
	}
	else {
		return s + " is ruled by Bob.";
	}
}

int main() {
	vector<char> vc = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
	for (char c : vc) vow[c]=1;

	int t; cin>>t;
	string ans[t];

	for (int i=0; i<t; i++) {
		string s; cin>>s;
		ans[i]=solve(s);
	}

	int i=1;
	for (string s : ans) {
		cout << "Case #" << i << ": " << s << endl;
		i++;
	}
}