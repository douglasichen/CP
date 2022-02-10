#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<int,int> uniqCnt;
vector<int> uniq;

unordered_map<int,pair<int, unordered_map<int,bool>>> uniqHeightCnt1;	// count and taken indexes;
vector<int> uniqHeight;

int main() {
	// input
	cin>>n;
	for (int i=0; i<n; i++) {
		int l; cin>>l;
		if (uniqCnt[l]==0) uniq.push_back(l);
		uniqCnt[l]++;
	}

	// combinations
	for (int i=0; i<uniq.size()-1; i++) {
		for (int o=i+1; o<uniq.size(); o++) {
			//calc data
			int l1=uniq[i], l2=uniq[o];
			int l=l1+l2;
			
			// set data
			if (uniqHeightCnt1[l].first==0) uniqHeight.push_back(l);
			unordered_map<int,bool> takenIndexes=uniqHeightCnt1[l].second;
			if (!takenIndexes[i] && !takenIndexes[o]) {
				uniqHeightCnt1[l].first++;

				// update
				takenIndexes[i]=1;
				takenIndexes[o]=1;
				uniqHeightCnt1[l].second=takenIndexes;
			}
			
			// uniqHeightCnt[l][1]=i;
			// uniqHeightCnt[l][2]=o;
		}
	}
	int best=0;
	for (int h : uniqHeight) {
		best=max(best,uniqHeightCnt[h].first);
	}
	int cnt=0;
	for (int h : uniqHeight) {
		if (uniqHeightCnt[h].first==best) cnt++;	
	}
	cout << best << ' ' << cnt << endl;

}