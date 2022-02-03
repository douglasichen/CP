#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


bool sorter (string a, string b) {
	if (a.length() != b.length()) return a.length() < b.length();
	return a < b;
}

string solve(vector<string> group) {
	sort(group.begin(), group.end(), sorter);
	// for (int i=0; i<group.size(); i++) cout<<group[i]<<endl;
	for (int i=0; i<group.size()-1; i++) {
		string s = group[i];
		for (int o=i+1; o<group.size(); o++) {
			string ns = group[o];
			if (s==ns) return "No";
			if (ns.substr(0,s.length()) == s) return "No";
			if (ns.length() == s.length()) continue;
			// cout<<ns.substr(ns.length()-s.length(), s.length()) <<endl;
			if (ns.substr(ns.length()-s.length(), s.length()) == s) return "No";
		}
	}
	return "Yes";

	// int minL = 1000;
	// for (int i=0; i<group.size(); i++) if (group[i].length() < minL) minL = group[i].length();
	// for (int i=0; i<minL; i++) {
	// 	vi map('b'+1);
	// 	for (int o=0; o<3; o++) {
	// 		map[group[o][i]++;
	// 	}
	// }
}

int main() {
	vector<vector<string>> v;
	int n; cin>>n;

	for (int i=0; i<n; i++) {
		vector<string> temp;
		for (int o=0; o<3; o++) {
			string s; cin>>s;
			temp.PB(s);
		}
		// cout<<"hello"<<endl;
		cout<< solve(temp) <<endl;
	} 
}