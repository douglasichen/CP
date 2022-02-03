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


bool isPerm(vector<int> a, vector<int> b) {
	return a==b;
}

int solve(string n, string h) {
	if (h.size()<n.size()) return 0;
	hash<string> hasher;
	int c=0;
	unordered_map<size_t,bool> u;
	
	string s="";
	vector<int> nCount('z'+1);
	vector<int> cCount('z'+1);


	string ss="";
	for (int i=0; i<n.size(); i++) {
		nCount[n[i]]++;
		cCount[h[i]]++;
		ss+=h[i];
	}
	if (cCount==nCount) {
		c++;
		u[hasher(ss)]=true;
	}

	for (int i=n.size(); i<h.size(); i++) {
		cCount[h[i]]++;
		cCount[h[i-n.size()]]--;

		ss.erase(ss.begin(), ss.begin()+1);
		ss+=h[i];

		if (isPerm(cCount,nCount)) {
			size_t hash_s = hasher(ss);
			if (!u[hash_s]) {
				c++;
				u[hash_s] = true;
			}
		}
	}

	return c;
}

int main() {
	string n,h; cin>>n>>h;
	cout << solve(n,h) << endl;
}