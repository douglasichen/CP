#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,P=0; cin>>N;
	vector<vector<int>> V(N,vector<int>(2));
	for (int i=0; i<N; i++) {
		cin>>V[i][0]>>V[i][1];
		P+=1<<i;
	}
	long long ans=LLONG_MAX;
	for (int i=1; i<=P; i++) {
		int at=i,o=0;
		long long a=1,b=0;
		while (at) {
			if (at&1) {
				a*=V[o][0];
				b+=V[o][1];
			}
			at>>=1;
			o++;
		}
		ans=min(ans,abs(a-b));
	}

	cout << ans << endl;

}