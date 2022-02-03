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

bool sorter (pair<char, string> a, pair<char, string> b) {
	return a.S.length() < b.S.length();
}

int main() {
	// vector<string> v(91);
	vector<pair<char, string>> v;
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		char c; string code; cin>>c>>code;
		v.PB({c,code});
	}
	string find; cin>>find;
	sort(v.begin(), v.end(), sorter);
	string ans = "";
	int start = 0;
	int c =0;
	while (start < find.length()) {
		for (int i=0; i<v.size(); i++) {
			string str = v[i].S;
			string sub = find.substr(start, str.length());
			if (str == sub) {
				ans += v[i].F;
				start += str.length();
				
				break;
			}
		}
	}
	cout<<ans<<endl;
}