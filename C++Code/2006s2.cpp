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
	vector<char> v(200);
	string a; getline(cin,a);
	string b; getline(cin,b);
	string c; getline(cin,c);
	// cout<<b<<endl;

	for (int i=0; i<a.length(); i++) {
		v[b[i]] = a[i];
	}
	string s = "";
	for (int i=0; i<c.length(); i++) {
		if (v[c[i]]!=0) {
			s+=v[c[i]];
		}
		else {
			s+='.';
		}
	}
	cout<<s<<endl;
}