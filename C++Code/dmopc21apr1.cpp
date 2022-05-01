#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<int> ans;
	multiset<int> MS;
	for (int i=0,a; i<N; i++) {
		cin>>a;
		MS.emplace(a);
	}
	ans.push_back(*MS.begin());
	MS.erase(MS.begin());
	while (ans.size()<N) {
		int a=ans.back();
		auto lb=MS.lower_bound(M-a);
		if (lb==MS.end()) break;
		ans.push_back((*lb));
		MS.erase(lb);
	}
	if (ans.size()!=N) cout << -1 << endl;
	else {
		for (int i : ans) cout << i << ' ';
		cout << endl;
	}
}