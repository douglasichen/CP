#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	string N,H; cin>>N>>H;
	if (N.size()>H.size()) {
		cout << 0 << endl;
		return 0;
	}
	// set
	unordered_map<char,int> proper;
	for (char c='a'; c<='z'; c++)
		proper[c]=0;

	// data
	for (char c : N)
		proper[c]++;
	
	// set
	string sub="";
	unordered_map<char,int> mine;
	for (char c='a'; c<='z'; c++)
		mine[c]=0;

	// data
	for (int i=0; i<N.size(); i++) {
		char c = H[i];
		mine[c]++;
		sub.push_back(c);	// add to substr
	}

	int ans=0;
	hash<string> h;
	unordered_map<size_t,bool> found;
	if (mine==proper) {
		size_t hashed=h(sub);
		found[hashed]=1;
		ans++;
	}

	int first=0;
	int bound=H.size()-N.size()+1;
	for (int i=1; i<bound; i++) {
		char leaving=H[i-1];
		// sub=sub.substr(1,sub.size()-1);
		// sub.erase(0,1);

		char newLast=H[i+N.size()-1];
		sub.push_back(newLast);
		first++;

		mine[leaving]--;
		mine[newLast]++;

		if (mine==proper) {
			sub.erase(0,first);
			first=0;
			// sub = H.substr(i,N.size());
			// cout << sub << endl;
			size_t hashed=h(sub);
			if (!found[hashed]) {
				ans++;
				found[hashed]=1;
			}
		}
	}
	cout << ans << endl;
}