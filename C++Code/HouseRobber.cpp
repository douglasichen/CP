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



void printVp(vector<pi> vp) {
	for(pi p : vp) {
		cout << "(" << p.F << ' ' << p.S << "), ";
	}
	cout << endl;
}

bool sorter(pi a, pi b) {
	return a.F > b.F;
}

bool neighborsUsed(int n, unordered_map<int,bool> used, int i) {
	if (i > 0 && i < n-1) {
		int a = i-1, b = i+1;
		if (used[a] || used[b]) return true;
	}
	else {
		if (i==0) {
			if (used[i+1]) return true;
		}
		else {
			if (used[i-1]) return true;
		}
	}
	return false;
}

int solve(int n, vi v) {
	unordered_map<int,bool> used;
	vector<pi> pri(n);
	FOR(i,v.size()) {
		pri[i] = {v[i],i};
	}

	sort(pri.begin(), pri.end(), sorter);

	// printVp(pri);

	int ans=0;
	FOR(i,n) {
		if (!neighborsUsed(n,used,pri[i].S)) {
			// cout << pri[i].S << " dont have use neighbors giving me: " << v[pri[i].S] << endl;
			ans+=v[pri[i].S];
			used[pri[i].S]=true;
			// cout << pri[i].S << " is now used" << endl;
		}
	}

	
	return ans;
}

int main() {
	// int n; cin>>n;
	// vi v(n);
	// FOR(i,n) cin>>v[i];
	vi v = {2,1,1,60,1};
	int n = v.size();
	cout << solve(n,v);
}