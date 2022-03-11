#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int K,D; cin>>K>>D;
	int m=10;
	bool t=0;
	bool has0=0;
	for (int i=0; i<D; i++) {
		int inp; cin>>inp;
		if (inp!=0) {
			t=1;
			m=min(m,inp);
		}
		else has0=1;
	}
	string s="";
	if (has0 && t==0) s="-1";
	else {
		if (has0) {
			s+=('0'+m);
			for (int i=0; i<K-2; i++) s+='0';
			s+=('0'+m);
		}
		else {
			for (int i=0; i<K; i++) s+=('0'+m);
		}
	}
	cout << s << endl;
}
