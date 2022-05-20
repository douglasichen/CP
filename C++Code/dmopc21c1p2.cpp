#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N),ans;
	vector<bool> done(N);
	set<int,greater<int>> S;
	for (int i=0; i<N; i++) cin>>V[i],S.emplace(V[i]);

	// for (int i : S) cout << i << " "; cout << endl;

	for (int e : S) {
		int sz=1;
		for (int i=0; i<N; i++) {
			if (V[i]==e) {
				ans.push_back(sz),done[i]=1;
				if (ans.size()<2*N-1) ans.push_back(-(sz-1));
				else ans.push_back(-N);
			}
			else if (!done[i]) sz++;
		}
	}
	int cnt=0;
	for (int i : ans) cnt+=i!=0;
	cout << cnt << endl;
	for (int i : ans) if (i) cout << i << endl;
}