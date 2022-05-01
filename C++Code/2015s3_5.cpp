#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int G,N; cin>>G>>N;
	set<int> S;
	for (int i=0; i<=N; i++) S.emplace(i);
	int ans=0;
	for (int i=0,inp; i<N; i++) {
		cin>>inp;
		auto it=S.upper_bound(inp);
		it--;
		if ((*it)==0) break;
		else {
			ans++;
			S.erase(it);
		}
	}
	cout << ans << endl;
}