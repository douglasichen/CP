#include <bits/stdc++.h>
using namespace std;

int N,M;
unordered_map<int,int> RV;
int ans=0;
int inp, val;

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	cin>>N>>M;
	for (int i=0; i<N; i++) {
		cin>>inp;
		if (inp==-1) continue;
		val=inp-i;
		RV[val]++;
	}
	for (int i=0; i<M; i++) {
		cin>>inp;
		if (inp==-1) continue;
		val=inp-i;
		if (RV[val]) {
			RV[val]--;
			ans++;
		}
	}
	
	cout << ans << endl;
}