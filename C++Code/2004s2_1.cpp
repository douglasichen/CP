#include <bits/stdc++.h>
using namespace std;

int n,k;

void solve() {

}

bool sorter(vector<int> a, vector<int> b) {
	// if (a[1]==b[1]) {
	// 	return a[0]<b[1];
	// }
	return a[1]>b[1];
}

int main() {
	cin>>n>>k;
	vector<vector<vector<int>>> C(k, *(new vector<vector<int>>(n, *(new vector<int>(2)))));
	vector<int> wr(n,0);
	vector<int> s(n,0);
	for (int i=0; i<k; i++) {
		for (int j=0; j<n; j++) {
			// contestant #
			C[i][j][0]=j;
			// value
			cin>>C[i][j][1];
			C[i][j][1] += s[j];
			s[j]=C[i][j][1];
		}
		sort(C[i].begin(), C[i].end(), sorter);

		// for (vector<int> p : C[i]) cout << p[0] << ',' << p[1] << ' ';
		// cout << endl;

		int rank=0;
		// cout << "rank: ";
		for (int j=0; j<n; j++) {
			if (j>0) {
				int scoreA=C[i][j][1], scoreB=C[i][j-1][1];
				if (scoreA!=scoreB) rank++;
			}
			wr[C[i][j][0]] = max(wr[C[i][j][0]],rank);
			// cout << rank << ' ';
		}
		// cout << endl;
	}


	vector<int> best;
	for (int i=0; i<n; i++) {
		if (C[k-1][i][1]==C[k-1][0][1]) best.push_back(C[k-1][i][0]);
	}
	sort(best.begin(), best.end());
	for (int i : best) {
		cout << "Yodeller " << i+1 << " is the TopYodeller: score " << C[k-1][0][1] << ", worst rank " << wr[i]+1 << endl;
		// Yodeller 5 is the TopYodeller: score 996, worst rank 5
	}
}