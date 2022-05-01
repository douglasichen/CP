#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N,L,S; cin>>N>>L>>S;
	vector<long long> dif(L);
	for (int i=0; i<N; i++) {
		int a,b,c; cin>>a>>b>>c; a--; b--;
		dif[a]+=c;
		dif[b+1]-=c;
	}
	for (int i=1; i<L; i++) {
		dif[i]+=dif[i-1];
	}

	int ans=0;
	for (int i=0; i<L; i++) {
		if (dif[i]<S) ans++;
	}
	cout << ans << endl;
}