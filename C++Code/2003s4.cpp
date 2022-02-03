#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


ll solve(string s) {
	
	vector<bool> alph('z'+1);
	// vi chars;
	int charsC=0;
	for (char c : s) {
		if (!alph[c]) charsC++;
		alph[c]=true;
	}

	ll sb = (ll)charsC;
	// cout<<sb<<endl;

	// for (int i=0; i<s.size()-1; i++) {
	// 	strs.PB(s);
	// }

	for (int a=2; a<=s.size()-1; a++) {
		unordered_map<string,bool> u;
		for (int b=0; b<s.size()-(a-1); b++) {
			string ss = s.substr(b, a);
			// cout<<ss<<endl;
			if (u.find(ss) == u.end()) {
				// cout<<ss<<" doesnt exist"<<endl;
				u.insert({ss,false});
				sb++;
				// cout<<sb<<endl;
			}
		}
	}
	sb+=2;
	if (s.length()==1) sb--;

	// for (int i=0; i<chars.size(); i++) {
	// 	cout<<chars[i]<<": "<<alph[chars[i]]<<endl;
	// }


	return sb;

	// for (int i=0; i<chars.size(); i++) {
	// 	char c = chars[i];
	// 	if (alph[c]>1) 
	// }
}

int main() {
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		string s; cin>>s;
		cout<<solve(s)<<endl;
	}
}