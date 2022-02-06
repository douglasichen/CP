#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	string s; cin>>s;
	int nL=0,nM=0;
	for (char c : s) {
		nL+=(c=='L');
		nM+=(c=='M');
	}
	stack<int> LinM;
	for (int i=nL; i<nL+nM; i++) {
		if (s[i]=='L')
			LinM.push(i);
	}
	
	int rL=0, rM=0;
	for (int i=0; i<nL; i++) {
		if (s[i]!='L') {
			rL++;
			if (s[i]=='M') {
				if (!LinM.empty()) {
					int lInd=LinM.top();
					swap(s[i],s[lInd]);
					LinM.pop();
				}
			}
		}
	}
	for (int i=nL; i<nL+nM; i++) {
		if (s[i]!='M')
			rM++;
	}
	
	int ans=rL+rM;
	cout << ans << endl;
}