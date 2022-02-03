#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


int solve(string k, string s) {
	if (s.length()==1) return 0;
	vi pos('z'+1);
	for (int i=1; i<=k.length(); i++) {
		pos[k[i]] = i;
	}
	int t=0;
	for (int i=1; i<s.length(); i++) {
		char c1 = s[i];
		char c2 = s[i-1];
		t += abs(pos[c1] - pos[c2]);
	}
	return t;
}

int main() {
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		string k,s; cin>>k>>s;
		cout<< solve(k,s)<<endl;
	}
}