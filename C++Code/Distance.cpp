#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

int d(pi a, pi b) {
	return abs(a.F-b.F) + abs(a.S-b.S);
}

void solve(pi p) {
	int goal = d({0,0},p);
	int maxX = max(a.F, b.F);
	int maxY = max(a.S, b.S);
	
}

int main() {
	int t; cin>>t;
	for (int i=0; i<t; i++) {
		pi p;
		cin>>p.F>>p.S;
		solve(p);
	}
}