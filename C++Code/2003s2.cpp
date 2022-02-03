#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

vector<bool> vow('z'+1);


string findSyl(string s) {
	int vLoc=-1;
	string fw = "";
	for (ll i=(ll)s.length()-1; i>=0; i--) {
		if (s[i]==' ') break;
		fw+=s[i];
		if (vow[s[i]]) {
			vLoc = i;
			break;
		}
	}
	// cout<<fw<<endl;
	
	if (vLoc==-1) {
		string rfw="";
		for (int i=fw.size()-1; i>=0; i--) {
			rfw+=tolower(fw[i]);
		}
		return rfw;
	}

	string ss = "";
	for (int i=vLoc; i<s.length(); i++) {
		if (s[i]==' ') break;
		ss+=tolower(s[i]);
	} 
	return ss;
}

string solve(vector<string> ss) {
	vector<string> syl(4);
	for (int i=0; i<4; i++) {
		syl[i] = findSyl(ss[i]);
		// cout<<syl[i]<<endl;
	}
	bool perf = syl[0]==syl[1] && syl[1]==syl[2] && syl[2]==syl[3];
	if (perf) return "perfect";

	bool even = syl[0]==syl[1] && syl[2]==syl[3];
	if (even) return "even";
	
	bool cross = syl[0]==syl[2] && syl[1] == syl[3];
	if (cross) return "cross";
	
	bool shell = syl[0]==syl[3]&&syl[1]==syl[2];
	if (shell) return "shell";
	
	return "free";
	// bool 
}

string tl(string s) {
	for (ll i=0; i<(ll)s.length(); i++) {
		s[i] = tolower(s[i]);
	}
	return s;
}

int main() {
	vow['a'] = true;
	vow['e'] = true;
	vow['i'] = true;
	vow['o']=true;
	vow['u']=true;

	int n; cin>>n;
	cin.ignore();
	for (int i=0; i<n; i++) {
		vector<string> ss(4);
		for (int o=0; o<4; o++) {
			string s; getline(cin,s);
			s = tl(s);
			// cout<<s<<endl;
			ss[o] = s;
		}
		cout << solve(ss) << endl;
	}
}