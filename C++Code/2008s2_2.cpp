#include <bits/stdc++.h>
using namespace std;

bool inCircle(int r, int y, int x) {
	float dis = sqrt(y*y + x*x);
	bool ans = (dis <= (float)r);
	// cout << x << ' ' << y << ": " << ans << endl;
	return ans;
}

int solve(int r) {
	int ans = 1 + r*4;
	int c=0;
	for (int x=1; x<=r; x++) {
		for (int y=r; y>=1; y--) {
			c += (x-1);
			while (inCircle(r,y-1,x) && x<=r) x++;
		}
	}
	c*=4;
	ans += c;
	return ans;
}

int main() {
	vector<int> ans;
	int n=1;
	while (n) {
		cin>>n;
		if (n==0) break;
		ans.push_back(solve(n));
	}
	for (int i : ans) cout << i << endl;
}