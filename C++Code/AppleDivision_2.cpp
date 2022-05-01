#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N; cin>>N;
	vector<int> V(N);
	long long sm=0;
	for (int i=0; i<N; i++) {
		cin>>V[i];
		sm+=V[i];
	}
	
	long long ans=INT_MAX;
	int mx=1<<20;	// actually one less but iteration i<mx so it works
	for (int i=0; i<mx; i++) {
		long long a=0;
		int ind=0, e=i;
		while (e && ind<N) {
			if (e&1) a+=V[ind];
			ind++;
			e>>=1;
		}
		if (ind==N) {
			long long b=sm-a, dif=abs(a-b);
			ans=min(ans,dif);
		}
	} 
	cout << ans << endl;
}