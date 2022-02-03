#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

pi bounds;

int clamp(int x, int min, int max) {
	if (x < min) x = min;
	if (x > max) x = max;
	return x;
}

pi add(pi a, pi b) {
	int x = a.F + b.F;
	int y = a.S + b.S;
	x = clamp(x,0, bounds.F);
	y = clamp(y,0, bounds.S);
	return {x,y};
}

int main() {
	cin>>bounds.F>>bounds.S;
	pi dir = {-1,-1};
	pi pos = {0,0};
	while (true) {
		cin>>dir.F>>dir.S;
		if (dir.F == 0 && dir.S==0) break;
		pos = add(pos, dir);
		cout << pos.F<<' ' << pos.S <<endl;
	}
}