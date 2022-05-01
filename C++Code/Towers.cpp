#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	multiset<int> S;
	for (int i=0; i<N; i++) {
		int inp; cin>>inp;
		if (S.empty()) S.emplace(inp);
		else {
			auto go=S.upper_bound(inp);
			if (go!=S.end()) S.erase(go);
			S.emplace(inp);
		}
	}
	cout << S.size() << endl;
}