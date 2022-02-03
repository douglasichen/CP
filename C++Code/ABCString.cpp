#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


string solve(string s) {
	if (s[s.length()-1]==s[0]) return "NO";
	char first = s[0];
	vi ct('C'+1);
	for (int i=0; i<s.length(); i++) {
		ct[s[i]]++;
	}
	// for (int i='A'; i<='C'; i++) cout<<ct[i]<<endl;
	
	string ot = "";
	
	for (int i='A'; i<='C'; i++) {
		if (ct[i]!=0) {
			if (i!=first) ot += i;
		}
	}
	if (ot.length()==2) {
		if (ct[first] == ct[ot[0]] + ct[ot[1]]) return "YES";
		if (ct[first] + ct[ot[0]] == ct[ot[1]]) {
			if (ct[s.length()-1] != ot[0]) return "YES";
		}
		if (ct[first] + ct[ot[1]] == ct[ot[0]]) {
			if (s[s.length()-1] != ot[1]) return "YES";
		}
	}
	else if (ot.length()==1) {
		if (ct[first] == ct[ot[0]]) return "YES";
	}
	
	return "NO";
}

int main() {
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		string s; cin>>s;
		cout<<solve(s) << endl;
	}
}