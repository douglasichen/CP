#include <bits/stdc++.h>
using namespace std;

string N,H;
unordered_map<size_t,bool> found;
hash<string> h;

int c2i(char c) {
	return c-'a'+1;
}

int solve() {
	int nSize=N.size(), hSize=H.size();
	if (nSize>hSize) return 0;

	int ans=0;
	int proper=0;
	for (char c : N)
		proper+=c2i(c);
	
	int mine=0;
	for (int i=0; i<nSize; i++) {
		mine+=c2i(H[i]);
	}
	if (mine==proper) {
		found[h(H.substr(0,nSize))]=1;
		ans++;
	}

	// search
	string sub=H.substr(0,N.size());
	for (int i=1; i<=hSize-nSize; i++) {
		int behind=c2i(H[i-1]), next=c2i(H[i+nSize-1]);
		mine-=behind;
		mine+=next;

		if (mine==proper) {
			sub=H.substr(i,nSize);
			size_t hSub=h(sub);
			
			if (!found[hSub]) {
				found[hSub]=1;
				ans++;
			}
		}
	}

	return ans;
}

int main() {
	cin>>N>>H;
	cout << solve() << endl;
}