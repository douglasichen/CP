#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


vector<pi> top = {
	{2,2},
	{3,3},
	{4,2},
};

bool inBounds(pi target, )

string solve(int m, int x, int y) {
	ll length = pow(5,m);
	ll leftBound = length/5;
	ll rightBound = leftBound*4;
	if (x<leftBound|| x>rightBound) return "empty";
	
	pi target = {x,y};



	ceil(target/5.0);
	for (int i=1; i<=m; i++) {
		int level = i;
		int rawLevel = pow(5,level);
		if (rawLevel <= target) {
			int xBox = ceil(target/rawLevel);
			
		}
	}

	bool dead = true;
	pi spot = top[0];
	int level = 1;
	int leftBoundInc = (spot.F+1)*pow(5,level)-4;
	int bottomBoundInc = (spot.S+1)*pow(5,level)-4;
	cout<<leftBoundInc<<' '<<bottomBoundInc<<endl;
	pi lTarget = (target-target/pow(5,level));
	if (inBounds(lTarget, leftBoundInc, bottomBoundInc)) {

	}
	// if (x>leftBound*3) {

	// }	
	// else if (x>leftBound*2) {

	// }
	// else {

	// }

	return "empty";
}

int main() {
	int t; cin>>t;
	for (int i=0; i<t; i++) {
		int m, x, y; cin>>m>>x>>y;
		cout<<solve(m,x,y)<<endl;
		break;
	}
}