#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<int,int> uniqCnt;
vector<int> uniq;

unordered_map<int,int> uniqHeightCnt;	// count;
vector<int> uniqHeight;

void solve() {
	if (n==1) {
		cout << 1 << ' ' << 1 << endl;
		return;
	}
	if (uniq.size()==1) {
		cout << n << ' ' << 1 << endl;
		return;
	}
	// combinations
	for (int i=0; i<uniq.size()-1; i++) {
		for (int o=i+1; o<uniq.size(); o++) {
			int l1=uniq[i], l2=uniq[o];
			int l=l1+l2;
			if (uniqHeightCnt[l]==0) uniqHeight.push_back(l);
			// uniqHeightCnt[l]++;
			uniqHeightCnt[l]+=min(uniqCnt[l1], uniqCnt[l2]);
		}
	}
	int best=0;
	for (int h : uniqHeight) {
		best=max(best,uniqHeightCnt[h]);
	}

	int cnt=0;
	for (int h : uniqHeight) {
		if (uniqHeightCnt[h]==best) cnt++;
	}
	cout << best << ' ' << cnt << endl;
}

int main() {
	// input
	cin>>n;
	for (int i=0; i<n; i++) {
		int w; cin>>w;
		if (uniqCnt[w]==0) uniq.push_back(w);
		uniqCnt[w]++;
	}
	solve();
}