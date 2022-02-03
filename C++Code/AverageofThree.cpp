#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define uMap unordered_map
#define vec vector
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(x,n) for(int x = 0; x < n; ++x)

vi solve(int n) {
	return {n-1,n,n+1};
}

int main() {
	int t; cin>>t;
	vector<vi> ans;
	FOR(i,t) {
		int n; cin>>n;
		ans.PB(solve(n));
	}
	for (vi i : ans) {
		for (int o : i)
			cout << o << ' ';
		cout << endl;
	}
}