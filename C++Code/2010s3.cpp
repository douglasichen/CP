#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

bool sorter(pair<float, pair<int,int>> a, pair<float, pair<int,int>> b) {
	return a.F > b.F;
}

void solve(int h, int k, vi ad) {
	if (h<=k) {
		cout<<0<<endl;
		return;
	}


	sort(ad.begin(), ad.end());
	
	vector<pair<float, pair<int,int>>> ds;
	for (int i=0; i<ad.size()-1; i++) {
		for (int o=i+1; o<ad.size(); o++) {
			float minDistance = min(ad[o] - ad[i], 1000000 - (ad[o] - ad[i]));
			ds.PB({minDistance, {ad[i],ad[o]}});
		}
	}
	sort(ds.begin(), ds.end(), sorter);
	
	// for (int i=0; i<ds.size(); i++) {
	// 	cout<<ds[i].F<<": ("<<ds[i].S.F<<","<<ds[i].S.S<<")"<<endl;
	// }


	vi minDs(1000000,500001);

	for (int i=0; i<ds.size(); i++) {
		int d = ds[i].F;
		if (d < minDs[ds[i].S.F]) minDs[ds[i].S.F] = d;
		if (d < minDs[ds[i].S.S]) minDs[ds[i].S.S] = d;
	}

	for (int i=0; i<ad.size(); i++) {
		cout<<ad[i]<<": "<<minDs[ad[i]]<<endl;
	}
	

	if (h-k == 1) {
		
		return;
	}

}

int main() {
	int h; cin>>h;
	vi ad(h);
	for (int i=0; i<h; i++) {
		cin>>ad[i];
	}
	int k; cin>>k;
	solve(h,k,ad);
	
	
}