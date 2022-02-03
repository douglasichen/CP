#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int absSubPi(pair<int,int> a, pair<int,int> b) {
	int xDif = abs(a.first - b.first), yDif = abs(a.second - b.second);
	int ans = max(xDif, yDif);
	return ans;
}

int main() {
	int n; cin>>n;
	vector<pair<int,int>> goal(n*n+1);
	vector<vector<int>> real(n, *(new vector<int>(n)));
	int num=0;
	pair<int,int> badLoc = {-1,-1};
	for (int y=0; y<n; y++) {
		for (int x=0; x<n; x++) {
			cin>>real[y][x];
			num++;
			goal[num]={y,x};

			if (badLoc.first==-1) {
				if (real[y][x]!=num) {
					badLoc={y,x};
				}
			}
		}
	}
	// cout << badLoc.first << ' ' << badLoc.second << endl;
	pair<int,int> rightLoc = goal[real[badLoc.first][badLoc.second]];
	int ans = absSubPi(badLoc, rightLoc) + 1;
	cout << ans << endl;
}