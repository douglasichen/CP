#include <bits/stdc++.h>
using namespace std;

bool solve(string s) {
	
	int k=0;
	vector<bool> taken('z'+1);
	for (char c : s) {
		if (c>='a' && c<='z') {
			if (taken[c]) return false;
			taken[c]=true;
			k++;
		}
		else return false;
	}
	return k==26;
}

int main() {
	int n; cin>>n;
	cin.ignore();
	vector<bool> ans;
	for (int i=0; i<n; i++) {
		string s; getline(cin,s);
		ans.push_back(solve(s));
	}
	for (bool b : ans) {
		cout << (b ? "OK." : "Nope.") << endl;
	}
}