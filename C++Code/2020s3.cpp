#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


void solve() {

}

int main() {
	string n, s; cin>>n>>s;
	
	vi mv('z'+1);
	for (char c : n) {
		mv[c]++;
	}
	 
	ll cnt = 0;
	unordered_map<string, bool> u;
	for (int a=0; a<s.length()-n.length()+1; a++) {
		string ts = s.substr(a, n.length());
		cout << endl;
		bool right = true;
		vi iv('z'+1);
		vi tv;
		for (char c : ts) {
			if (iv[s[c]]==0) tv.PB(c);
			iv[s[c]]++;
			if (mv[c]<iv[s[c]]) {
				right = false;
				break;
			}
		}
		if (right) {
			for (int i=0; i<tv.size(); i++) {
				if (mv[tv[i]]!=iv[tv[i]]) {
					right = false;
					break;
				}
			}
			string key = ts;
			
			if (u.find(key)!=u.end()) {
				if (!u[key]) u.insert({key,true});
				else continue;
			}
		}
		cnt+=right;
	}

	// int r = s.length()%n.length();
	// for (int a=0; a<r+1; a++) {
	// 	unordered_map<string, bool> u;
	// 	ll tCnt = 0; 
	// 	for (int b=a; b<s.length()-r+a; b+=n.length()) {
	// 		bool right = true;
	// 		vi iv('z'+1);
	// 		vi tv;
	// 		for (int c=b; c<n.length(); c++) { 
	// 			if (iv[s[c]]==0) tv.PB(c);
	// 			iv[s[c]]++;
	// 			if (mv[c]<iv[s[c]]) {
	// 				right = false;
	// 				break;
	// 			}
	// 		}
	// 		if (right) {
	// 			for (int i=0; i<tv.size(); i++) {
	// 				if (mv[tv[i]]!=iv[tv[i]]) {
	// 					right = false;
	// 					break;
	// 				}
	// 			}
	// 			string key = s.substr(b,n.length());
	// 			cout << key << endl;
	// 			if (u.find(key)!=u.end()) {
	// 				if (!u[key]) u.insert({key,true});
	// 				else break;
	// 			}
				
	// 		}
	// 		tCnt+=right;
	// 	}
	// 	cnt = max(cnt, tCnt);
	// }
	cout << cnt<<endl;
	

}