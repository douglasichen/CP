#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


void solve(int l, string s) {
	int l = 0, r = l-1;
	int a=0,b=0;
	for (int i=0; i<l; i++) {
		a += s[i] == 'a';
		b += s[i] == 'b';
	}
	while (l != r) {
		if (a > b) {
			if (s[l]=='a') l++;
			else r--;
		}
		else if (b > a) {
			if (s[l]=='b') l++;
			else r--;
		}
		else {
			cout << l << ' ' << r << endl;
			break;
		}
	}
 }

int main() {
	int n; cin>>n;
	
	for (int i=0; i<n; i++) {
		int l; cin>>l;
		string s; cin>>s;
		solve(l,s);
	}
}