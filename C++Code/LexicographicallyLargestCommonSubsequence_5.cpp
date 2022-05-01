#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<string> V(N);
	vector<vector<int>> F(N,vector<int>('z'+1));
	
	for (int i=0; i<N; i++) {
		cin>>V[i];
		for (char c : V[i]) F[i][c]++;
	}

	vector<bool> has('z'+1,1);
	for (char c='a'; c<='z'; c++) {
		for (vector<int> f : F) {
			if (f[c]==0) {
				has[c]=0;
				break;
			}
		}
	}

	string ans=""; ans.reserve(1e6);
	vector<int> starts(N);
	for (char want='z'; want>='a';) {
		if (has[want]) {
			ans+=want;
			for (int i=0; i<N; i++) {
				string s=V[i];
				bool fnd=0;
				for (int o=starts[i]; o<s.size(); o++) {
					F[i][s[o]]--;
					if (F[i][s[o]]<=0) has[s[o]]=0;
					if (s[o]==want) {
						starts[i]=o+1;
						break;
					}
				}
			}
		}
		if (!has[want]) want--;
	}
	
	if (ans.size()==0) cout << -1 << endl;
	else cout << ans << endl;

}