#include <bits/stdc++.h>
using namespace std;

void cntRange(int i, int j, string s, unordered_map<char,int> &cnt, bitset<'Z'+1> &has) {
	string multNum="";
	bool newEl=1;
	char prevEl=0;

	for (; i<=j; i++) {
		char c=s[i];
		if (isdigit(c) && newEl) {
			multNum+=c;
			newEl=0;
		}
		else if (isalpha(c)) {
			// check:
			newEl=0;

			int mult=(multNum=="" ? 1 : stoi(multNum));
			
			string sNum="";
			for (int o=i+1; isdigit(s[o]); o++) sNum+=s[o];
			int num=(sNum=="" ? 1 : stoi(sNum));

			cnt[c]+=num*mult;
			// cout << "add " << num*mult << " to " << c << ", due to: " << "num=" << num << " mult=" << mult << endl;

			// has map
			has[c]=1;
		}
		else if (c=='+') {
			multNum="";
			newEl=1;
		}
	}
}

bool solve(string s) {
	unordered_map<char,int> left,right;
	bitset<'Z'+1> lh, rh;

	int j=0;
	for (int i=0; i<s.size(); i++) {
		if (s[i]=='-') {
			j=i-1;
			break;
		}
	}
	cntRange(0,j,s,left,lh);
	cntRange(j+3,s.size()-1,s,right,rh);

	for (auto p=left.begin(); p!=left.end(); p++) {
		if (right[p->first]!=p->second) return 0;
	}
	for (int i=0; i<'Z'+1; i++) {
		if (lh[i]!=rh[i]) return 0;
	}
	return 1;

	// bool fnd['Z'+1];
	// memset(fnd,0,sizeof(fnd));
	// for (int k=0; k<s.size()/2; k++) {
	// 	if (!fnd[s[k]]) {
	// 		if (s[k]>='A' && s[k]<='Z') cout << s[k] << ": " << left[s[k]] << endl;
	// 		fnd[s[k]]=1;
	// 	}
	// }
	
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	bool ans[T];
	for (int i=0; i<T; i++) {
		string s; cin>>s;
		ans[i]=solve(s);
	}
	for (bool i : ans) cout << (i ? "DA" : "NE") << endl;
}