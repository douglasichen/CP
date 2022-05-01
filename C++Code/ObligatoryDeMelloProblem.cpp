#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	vector<bool> vow('z'+1,0);
	vow['a']=1;
	vow['e']=1;
	vow['i']=1;
	vow['o']=1;
	vow['u']=1;
	vow['y']=1;
	string s; cin>>s;
	int a=0;
	for (char c : s) a+=vow[c];
	cout << (a>=2 ? "good" : "bad") << endl;

}