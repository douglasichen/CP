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

hash<string> h;

bool solve(int n, vector<string> a, vector<string> b) {
	unordered_map<size_t, string> u;

	FOR(i,n) {
		string s1=a[i], s2=b[i];
		if (s1==s2) return false;
		size_t h1=h(s1), h2=h(s2);
		if ((u[h1]=="" || u[h1]==s2) && (u[h2]=="" || u[h2]==s1)) {
			u[h1]=s2;
			u[h2]=s1;
		}
		else return false;
	}
	return true;
}

int main() {
	
	int n; cin>>n;
	vector<string> a(n),b(n);
	FOR(i,n) cin>>a[i];
	FOR(i,n) cin>>b[i];

	bool ans=solve(n,a,b);
	cout << (ans ? "good" : "bad") << endl;
}