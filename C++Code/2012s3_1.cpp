#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> reads;
unordered_map<int,int> f;

bool sorter(int a, int b) {
	return f[a] > f[b];
}

int main() {
	cin>>n;
	for (int i=0; i<n; i++) {
		int r; cin>>r;
		if (f[r]==0)
			reads.push_back(r);
		f[r]++;
	}
	sort(reads.begin(), reads.end(), sorter);

	int bestFA=f[reads[0]],bestFB=-1;

	// get second best freq
	for (int r : reads) {
		if (f[r]!=bestFA) {
			bestFB=max(bestFB,f[r]);
		}
	}

	vector<int> rA, rB;
	for (int r : reads) {
		if (f[r]==bestFA)
			rA.push_back(r);
		else if (f[r]==bestFB)
			rB.push_back(r);
	}

	int ans=0;

	if (rA.size()==1) {
		if (rB.size()==1) {
			ans=abs(rA[0]-rB[0]);	
		}
		else {
			vector<int> best={-1,-1}; // r, dif
			for (int r : rB) {
				int dif=abs(r-rA[0]);
				if (dif>best[1])
					best={r,dif};
			}
			ans=best[1];
		}
	}
	else {
		// if (rB.size()==0) {
			int maxA=0, minA=INT_MAX;
			for (int r : rA) {
				maxA=max(r,maxA);
				minA=min(r,minA);
			}
			ans=abs(minA-maxA);
		// }
		// else {
		// 	int minA=INT_MAX, maxA=0, minB=INT_MAX, maxB=0;
		// 	for (int r : rA) {
		// 		minA=min(r,minA);
		// 		maxA=max(r,maxA);
		// 	}
		// 	for (int r : rB) {
		// 		minB=min(r,minB);
		// 		maxB=max(r,maxB);
		// 	}
		// 	int dif1=abs(minA-maxB), dif2=abs(maxA-minB);
		// 	ans=max(dif1,dif2);
		// }
	}
	cout << ans << endl;
}

