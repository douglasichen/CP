#include <bits/stdc++.h>
using namespace std;

int X,N;
vector<vector<int>> V;

// bool sorter(vector<int> a, vector<int> b) {
// 	return a[0]<b[0];
// }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>X>>N;
	V=*(new vector<vector<int>>(N));
	for (int i=0; i<N; i++) {
		int t,f; cin>>t>>f;
		V[i]={t,f};
	}

	
	int ans=0;
	vector<bool> drunk(N);
	for (int time=0; time<=500000; time++) {
		vector<int> best={-1,INT_MAX, INT_MAX};
		for (int i=0; i<N; i++) {
			int temp=V[i][0]-time, f=V[i][1]-time;
			if (!drunk[i]) {
				if (temp<=X || (temp-X<=f)) {
					if (f<best[2]) {
						best={i,temp,f};
					}
				}
			}
		}
		if (best[0]==-1) continue;
		else {
			cout << best[0] << ' ';
			drunk[best[0]]=1;
			ans++;
		}
	}

	cout << ans << endl;

}