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


void solve() {

}

int minCostClimbingStairs(vector<int>& cost) {
	int ans1 = cost[0];
	int i=0;
	while (i<cost.size()) {
		if (i<cost.size()-2) {
			if (i==cost.size()-4) {
				if (cost[i+2] <= cost[i+1] + cost[i+3]) ans1+=cost[i+2];
				else ans1 += cost[i+1] + cost[i+3];
				break;
			}
			else {
				if (cost[i+1] < cost[i+2]) {
					ans1+=cost[i+1];
					i++;
				}
				else {
					ans1+=cost[i+2];
					i+=2;
				}
			}
		}
		else break;
	}
	int ans2 = cost[1];
	i=1;
	while (i<cost.size()) {
		if (i<cost.size()-2) {
			if (i==cost.size()-4) {
				if (cost[i+2] <= cost[i+1] + cost[i+3]) ans2+=cost[i+2];
				else ans2 += cost[i+1] + cost[i+3];
				break;
			}
			else {
				if (cost[i+1] < cost[i+2]) {
					ans2+=cost[i+1];
					i++;
				}
				else {
					ans2+=cost[i+2];
					i+=2;
				}
			}
		}
		else break;
	}
	return min(ans1,ans2);
}

int main() {
	vi v = {0,1,2,2};
	cout << minCostClimbingStairs(v) << endl;
}