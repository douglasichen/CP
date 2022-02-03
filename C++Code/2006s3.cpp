#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


pi a,b;


bool collide(pi p1, pi p2) {
	int maxX = max(p1.F, p2.F);
	int maxY = max(p1.S, p2.S);
	int minX = min(p1.F, p2.F);
	int minY = min(p1.S, p2.S);

	bool aBound = a.F >= minX && a.F <= max.X || a.S >= minY && a.S <= maxY;
	bool bBound = b.F >= minX && b.F <= max.X || b.S >= minY && b.S <= maxY;
	return aBound
}

bool solve(vector<pi> v) {
	for (int i=0; i<v.size()-1; i++) {
		pi corn = v[i];
		pi nextCorn = v[i+1];
		if (collide(corn, nextCorn)) {
			return true;
		}
	}
	return false;
}

int main() {
	cin>>a.F>>a.S>>b.F>>b.S;
	int n; cin>>n;
	vector<vector<pi>> bld;
	for (int i=0; i<n; i++) {
		vector<pi> build;
		int corn; cin>>corn;
		for (int o=0; o<corn; o++) {
			pi cp; cin>>cp.F>>cp.S;
			build.PB(cp);
		}
		bld.PB(build);
	}
	int ans;
	for (int i=0; i<bld; i++) {
		ans+=solve(bld[i]);
	}
}