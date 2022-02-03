#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


void solve(string s) {
	char minC = 'z'+1;
	for (int i=0; i<s.length(); i++) {
		if (s[i] < minC) minC = s[i];
	}

	cout<<minC<<' ';
	bool found = false;
	for (int i=0; i<s.length(); i++) {
		if (found) {
			cout<<s[i];
		}
		else {
			if (s[i]!=minC) cout<<s[i];
		}
		if (s[i]==minC) {
			found = true;
		}
	}
	cout<<endl;
	
}

int main() {
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		string s; cin>>s;
		solve(s);
	}
}