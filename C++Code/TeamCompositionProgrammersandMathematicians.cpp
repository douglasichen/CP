#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


int solve(int a, int b) {
	if (a+b<4) return 0;
	vi v = {a,b};
	sort(v.begin(),v.end());
	
}

int main() {
	int t; cin>>t;
	for (int i=0; i<t; i++) {
		int a,b; cin>>a>>b;
		cout << solve(a,b) << endl;
	}
}