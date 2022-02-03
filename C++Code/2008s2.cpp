#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

bool isPen(pi p) {
	return sqrt(pos.F*pos.F+pos.S*pos.S))<=r;
}

int solve(int r) {
	int p=0;
	pi pos = {0, r};
	
	pi belowPos = {pos.F, pos.S-1};
	if (isPen(belowPos)) {
		if (pos.F>r) break;
		pos.F++;
		if (isPen(pen))
	} 
	else {
		pos.S--;
		p++;
	}
}

int main() {
	int n = -1;
	while (n!=0) {
		cin>>n;
		if (n==0) break;
		cout<<solve(n)<<endl;
	}
}