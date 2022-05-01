#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<string> V(N);
	vector<vector<deque<int>>> F(N);
	for (int i=0; i<N; i++) {
		cin>>V[i]; int sz=V[i].size();
		
		vector<deque<int>> f('z'+1);
		for (int o=0; o<sz; o++) {
			char c=V[i][o];
			f[c].push_back(o);
		}
		F[i]=f;
	}

	string ans="";
	vector<int> starts(N);
	for (char want='z'; want>='a'; want++) {
		bool allHas=1;
		for (vector<deque<int>> f : F) {
			if (f[want].size()==0) {
				allHas=0;
				break;
			}
		}
		if (allHas) {
			ans+=want;
			for (int i=0; i<N; i++) {
				
			}
		}
	}
	if (ans.size()==0) cout << -1 << endl;
	else cout << ans << endl;

}