#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,P; cin>>N>>P;
	int ans=0;
	vector<set<int>> V(7);
	for (int o=0; o<N; o++) {
		int i,inp; cin>>i>>inp;
		auto it=lower_bound(V[i].begin(),V[i].end(),inp);
		bool has=0;
		if (it!=V[i].end() && (*it)==inp) it++,has=1;
		if (!has) ans++;

		int a=V[i].size();
		V[i].erase(it,V[i].end());
		int b=V[i].size();
		ans+=a-b;
		V[i].emplace(inp);
	}
	cout << ans << endl;
}