#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int N,M;
string T;
vector<vector<int>> loc('z'+1,vector<int>(5e5+1));

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	for (int i=1; i<=N; i++) {
		char c; cin>>c;
		loc[c][i]=i;
	}
	for (char c='a'; c<='z'; c++) {
		for (int i=N-1; i>0; i--)
			if (!loc[c][i])
				loc[c][i]=loc[c][i+1];
	}

	cin>>T;
	long long ans=0;
	int at=1;
	for (int i=0; i<M;) {
		char c=T[i];
		if (loc[c][at]) {
			ans+=loc[c][at]-at+1;
			at=loc[c][at]+1;
			if (at>N) at=1;
			i++;
		}
		else if (at>1) {
			ans+=N-at+1;
			at=1;
		}
		else {
			ans=-1;
			break;
		}
	}
	cout << ans << endl;
}