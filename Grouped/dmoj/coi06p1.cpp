#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	unsigned int N; cin>>N;
	vector<unsigned int> V(N+1);
	for (unsigned int i=1; i<=N; i++) cin>>V[i];
	multiset<vector<unsigned int>> S;
	long long ans=N*1LL*(N-1)/2LL;
	for (unsigned int i=N; i>0; i--) {
		if (i<N) {
			auto it=S.upper_bound(vector<unsigned int>{V[i],0});
			if (it!=S.end()) {
				ans-=N-(*it)[1];
			}
		}
		S.emplace(vector<unsigned int>{V[i],i});
		if (i==0) break;
	}
	cout << ans << endl;
}