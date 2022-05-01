#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S; cin>>S;
	string U="";
	vector<int> has('Z'+1);
	for (char c : S) {
		if (has[c]==0) U+=c;
		has[c]++;
	}

	int cSig=-1;
	for (char c : U) {
		if (has[c]%2!=0) cSig=c;
	}

	string pre="";
	for (char c : U) {
		if (c!=cSig) {
			if (has[c]%2!=0) {
				cout << "NO SOLUTION" << endl;
				return 0;
			}
			else pre+=(string(has[c]/2,c));
		}
	}
	for (char c : pre) cout << c;
	if (cSig!=-1) {
		for (int i=0; i<has[cSig]; i++) cout << (char)cSig;
	}
	for (int i=pre.size()-1; i>=0; i--) cout << pre[i];
	cout << endl;
	
}