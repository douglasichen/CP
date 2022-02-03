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

int main() {
	vi heights(4001);
	int n; cin>>n;

	unordered_map<int,int> found;
	vi wl;
	FOR(i,n) {
		int num; cin>>num;
		found[num]++;
		if (found[num]==1) wl.PB(num);
	}

	vector<unordered_map<int,bool>> visited(n+1);
	for(int i : wl) cout << i << ' ';
	cout << endl;
	vi visH;
	FOR(i,wl.size()-1) {
		for (int o=i+1; o<wl.size(); o++) {
			int sum=wl[i]+wl[o];
			// cout << i << " vs " << o << endl;
			if (!visited[i][sum] && !visited[o][sum]) {
				if (heights[sum]==0) visH.PB(sum);
				heights[sum]++;
				visited[i][sum]=true;
				visited[o][sum]=true;
			}
		}
	}
	int maxL=0;
	for (int hInd : visH) {
		int h = heights[hInd];
		maxL=max(h,maxL);
		// if (h) cout << h << ' ';
	}	
	// cout << endl;
	int dif=0;
	for (int hInd : visH) {
		int h = heights[hInd];
		if (h==maxL) dif++;
	}
	cout << maxL << ' ' << dif << endl;
}