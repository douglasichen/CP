#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int n,k; cin>>n>>k;
	vector<string> v(n);
	for (int i=0; i<n; i++) {
		cin>>v[i];
	}

	// int ans=0;
	vector<int> scores(n);
	for (int q=0; q<k; q++) {
		int t=0,f=0;
		vector<int> newScores=scores;
		int minNewScore=INT_MAX;
		for (int p=0; p<n; p++) {
			t+=v[p][q]=='T';
			f+=v[p][q]=='F';
			newScores[p]++;
			minNewScore=min(minNewScore,newScores[p]);
		}

		if (!t || !f) {
			scores=newScores;
			// ans=minNewScore;
		}
		else {
			vector<int> scoringTrue=scores, scoringFalse=scores;
			for (int p=0; p<n; p++) {
				if (v[p][q]=='T')
					scoringTrue[p]++;
				else
					scoringFalse[p]++;
			}
			int minScT=scoringTrue[0], minScF=scoringFalse[0];

			for (int i : scoringTrue)
				minScT=min(minScT,i);
			for (int i : scoringFalse)
				minScF=min(minScF,i);

			// calculate the new answer
			// ans = max(minScT, minScF);

			if (minScT>=minScF) {
				scores=scoringTrue;
				// ans=minScT;
			}
			else {
				scores=scoringFalse;
				// ans=minScF;
			}
		}
		// for (int i : scores) cout << i << ' ';
		// cout << endl;
		
	}
	int ans=INT_MAX;
	for (int i : scores) ans = min(ans,i);
	cout << ans << endl;

}