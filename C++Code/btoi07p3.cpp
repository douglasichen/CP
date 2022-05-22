#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M,C; cin>>N>>M>>C;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];

	multiset<int> ms;
	for (int i=0; i<M; i++) ms.emplace(V[i]);
	
	vector<int> ans;
	if ((*(--ms.end()))-(*ms.begin())<=C) ans.push_back(0);
	int a=0;
	for (int b=M; b<N; b++) {
		ms.erase(ms.find(V[a]));
		ms.emplace(V[b]);
		if ((*(--ms.end()))-(*ms.begin())<=C) ans.push_back(a+1);
		a++;
	}
	if (ans.size()) {
		for (int i : ans) cout << i+1 << endl;
	}
	else cout << "NONE" << endl;
}