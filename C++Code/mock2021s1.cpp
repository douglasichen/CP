#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef vector<vector<int>> vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(x,n) for(int x = 0; x < n; ++x)

#define printV(v) FOR(x,v.size()) cout<<v[x]<<' '; cout<<endl;



void solve() {

}

string alph, s;

string removeAtI(string s, int i) {
	string ns = "";
	if (i>=1 && i < s.size()-1) {
		int l1=0, r1=i, l2=i+1, r2=s.size();
		ns += s.substr(l1,r1-l1) + s.substr(l2, r2-l2); 
	}
	else {
		if (i==0) ns = s.substr(1,s.size()-1);
		else ns = s.substr(0,s.size()-1);
	}
	return ns;
	
}


hash<string> h;

vector<string> ans;
vector<string> remove(vector<bool> isAlph, string s) {
	unordered_map<size_t,bool> remFound;
	vector<string> rems;

	FOR(i,s.size()) {
		if (isAlph[s[i]]=1) {
			string ns = removeAtI(s,i);
			size_t hashed = h(ns);
			if (!remFound[hashed]) {
				remFound[hashed]=true;
				ans.PB(ns);
			}
		}
	}
	return rems;
}

string addBehindI(string s, char c, int i) {
	// cout << "adding " << c << " behind " << i << endl;
	string ns = "";
	if (i>=1 && i < s.size()) {
		int l1=0, r1=i, l2=i, r2=s.size();
		ns += s.substr(l1,r1-l1);
		ns += c;
		ns += s.substr(l2, r2-l2); 
	}
	else {
		if (i==0) {
			ns += c;
			ns += s;
		}
		else {
			ns += s;
			ns += c;
		}
	}
	return ns;
	
}

vector<string> add(vector<bool> isAlph, string s) {
	unordered_map<size_t,bool> addFound;
	vector<string> adds;

	FOR(i,s.size()+1) {
		FOR(o,alph.size()) {
			char ac = alph[o];
			string ns = addBehindI(s, ac, i);
			size_t hashed = h(ns);
			// cout << ns << endl;
			if (!addFound[hashed]) {
				
				addFound[hashed] = true;
				ans.PB(ns);
			}
		}
	}
	return adds;
}

vector<string> change(vector<bool> isAlph, string s) {
	unordered_map<size_t, bool> changeFound;
	vector<string> changes;
	FOR(i,s.size()) {
		FOR(o,alph.size()) {
			if (s[i]==alph[o]) continue;
			string ns = s;
			ns[i]=alph[o];
			size_t hashed = h(ns);
			if (!changeFound[hashed]) {
				changeFound[hashed] = true;
				ans.PB(ns);
			}
		}
	}
	return changes;
}

bool sorter(string a, string b) {
	FOR(i,min(a.size(),b.size())) {
		if (a[i]==b[i]) continue;
		if (a[i]<b[i]) return true;
		else return false;
	}
	if (a.size()<b.size()) return true;
	return false;
}

int main() {
	
	cin>>alph>>s;
	vector<bool> isAlph(alph.size());
	for (char c : alph) isAlph[c] = true;
	
	remove(isAlph, s);
	add(isAlph, s);
	change(isAlph, s);

	sort(ans.begin(), ans.end());
	for (string s : ans) cout << s << endl;

	// vector<string> rems = remove(isAlph, s);
	// vector<string> adds = add(isAlph, s);
	// vector<string> changes = change(isAlph, s);

	// for (string s : rems) cout << s << endl;
	// for (string s : adds) cout << s << endl;
	// for (string s : changes) cout << s << endl;
}