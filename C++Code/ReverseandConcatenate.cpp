#include <bits/stdc++.h>
using namespace std;

bool sim(string s) {
	for (int i=0; i<s.size()/2; i++) {
		if (s[i]!=s[s.size()-i-1])
			return false;
	}
	return true;
}


int solve2(int n, int k, string s) {
	if (k==0) return 1;
	bool isSim=sim(s);
	if (isSim) return 1;
	return 2;	
}



int main() {
	int t; cin>>t;
	vector<int> ans(t);
	for (int i=0; i<t; i++) {
		int n,k; cin>>n>>k;
		string s; cin>>s;
		ans[i]=solve2(n,k,s);
	}
	for (int i : ans) cout << i << endl;
}