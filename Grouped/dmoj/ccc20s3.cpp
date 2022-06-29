#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'
#define ull unsigned long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	
	vector<short> A,B; 
	string a,b; cin>>a>>b;
	for (char c : a) A.push_back(c-'a');
	for (char c : b) B.push_back(c-'a');
	int aN=A.size(), bN=B.size();
	if (aN>bN) {
		cout << 0 << endl;
		return 0;
	}

	const int md=1e9+7;
	vector<int> FA(27), FB(27);
	ull val=0, lastP;
	for (ull i=0, prod=1; i<aN; i++, prod*=26, prod%=md) {
		FA[A[i]]++;
		FB[B[i]]++;
		val+=prod*B[i]%md;
		val%=md;
		lastP=prod;
	}

	map<ull,bool> has;
	int ans=0;
	if (FA==FB) has[val]=1, ans++;
	for (int l=0, r=aN; r<bN; l++, r++) {
		val-=B[l];
		val/=26; val%=md;
		val+=lastP*B[r]%md; val%=md;
		FB[B[l]]--;
		FB[B[r]]++;
		if (FB==FA) {
			if (!has[val]) ans++;
			else has[val]=1;
		}
	}

	cout << ans << endl;

}