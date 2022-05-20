#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,L; cin>>N>>L;
	vector<vector<int>> V(N,vector<int>(3));
	for (int i=0; i<N; i++) cin>>V[i][0]>>V[i][1]>>V[i][2];
	sort(V.begin(),V.end());

	long long ans=L,t=0;
	for (int i=0; i<N; i++) {
		t+=(i ? V[i][0]-V[i-1][0] : V[i][0]);
		
		vector<int> v=V[i];
		int a=v[1]+v[2],r=t%a;
		if (r<v[1]) {
			ans+=v[1]-r;
			t+=v[1]-r;
		}
	}
	cout << ans << endl;
}