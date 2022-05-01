#include <bits/stdc++.h>
using namespace std;

vector<string> ANS;
string A;

void rec(int K, int i, string s) {
	if (i==4) {
		ANS.push_back(s);
		return;
	}

	for (char c='a'; c<='z'; c++) {
		int a=min(c,A[i]), b=max(c,A[i]);
		int dis=min(b-a, a+26-b);
		if (dis<=K) {
			string ns=s; ns+=c;	
			int nK=K-dis;
			rec(nK,i+1,ns);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int K; cin>>K;
	cin>>A;

	rec(K,0,"");

	sort(ANS.begin(), ANS.end());
	for (string s : ANS) cout << s << endl;
}