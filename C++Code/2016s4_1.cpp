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

int n; 
vi rice;
vi score;


int maxCombineSize(int i) {
	while () {
		int a1 = comb(i, i+1);
		int a2 = comb(i, i-1);
		int b1 = comb(i, i+2);
		int b2 = comb(i, i-2);
		
	}
}

int main() {
	cin>>n;
	rice = *(new vi(n));
	score = *(new vi(n));
	FOR(i,n) {
		cin>>rice[i];
	}

	FOR(i,n) {
		score[i] = maxCombineSize(i);
	}
}