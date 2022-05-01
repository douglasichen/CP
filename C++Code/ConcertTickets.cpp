#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	multiset<int> have;
	for (int i=0; i<N; i++) {
		int inp; cin>>inp;
		have.emplace(inp);
	}

	for (int i=0; i<M; i++) {
		int want; cin>>want;
		if (have.size()==0) {
			cout << -1 << endl;
			continue;
		}
		multiset<int>::iterator val=have.upper_bound(want);

		int ans=-1;
		if (val==have.end()) val--;
		
		if (*val>want) {
			if (val!=have.begin()) val--;
		}
		if (*val<=want) ans=*val;


		if (ans!=-1) have.erase(val);
		cout << ans << endl;

	}
	
}