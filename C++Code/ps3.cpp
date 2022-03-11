#include <bits/stdc++.h>
using namespace std;


unordered_map<int,int> rCounts;

bool sorter(int a, int b) {
	return rCounts[a]>rCounts[b];
}

int main() {
	int n; cin>>n;
	
	vector<int> readings;
	for (int i=0; i<n; i++) {
		int r; cin>>r;
		if (rCounts[r]==0) readings.push_back(r);
		rCounts[r]++;
	} 
	sort(readings.begin(), readings.end(), sorter);

	// cout << "readings: ";
	// for (int r : readings) cout << r << ' ';
	// cout << endl;

	int freq1=rCounts[readings[0]], freq2=-1;
	for (int r : readings) {
		if (rCounts[r]!=freq1) {
			freq2=rCounts[r];
			break;
		}
	}	
	
	
	// group first best and second best
	vector<int> bestFreqs1, bestFreqs2;
	for (int r : readings) {
		if (rCounts[r]==freq1) {
			bestFreqs1.push_back(r);
		}
		else {
			if (freq2==-1) break;
			if (rCounts[r]!=freq2) break;
			bestFreqs2.push_back(r);
		}
	}
	
	// answer
	int ans=0;
	if (bestFreqs1.size()>1) {
		int mn=INT_MAX, mx=0;
		for (int r : bestFreqs1) {
			mn=min(r,mn);
			mx=max(r,mx);
		}
		ans=abs(mx-mn);
	}
	else {
		int dif=0;
		int bestR=readings[0];
		for (int r : bestFreqs2) {
			int nDif=abs(r-bestR);
			dif=max(dif,nDif);
		}
		ans=dif;
	}
	cout << ans << endl;
}