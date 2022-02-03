#include <bits/stdc++.h>
using namespace std;

int solve(string s, string f) {
	string k="";
	for (int i=s.size()-1; i>=0; i--) k+=s[i];

	int ind=-1;
	for (int i=0; i<k.size()-f.size(); i++) {
		string p = k.substr(i,f.size());
		if (p==f) {
			ind=i;
			break;
		}
	}
	if (ind==-1) return -1;

	int ans = k.size() - ind;
	return ans;
}

int main() {
	// cin.ignore();
	string s,f; 
	getline(cin,s);
	getline(cin,f);
	cout << solve(s,f) << endl;
		
}
