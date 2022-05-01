#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<string> V(N);
	vector<bool> B(N);
	for (int i=0; i<N; i++) {
		cin>>V[i];
		B[i]=V[i].find("yubo")!=string::npos;
	}
	vector<string> ans;
	if (N==1) {
		if (B[0]) ans.push_back(V[0]);
	}
	else {
		for (int i=0; i<N; i++) {
			if (B[i]) ans.push_back(V[i]);
			else {
				if (i==0) {
					if (B[i+1]) ans.push_back(V[i]);
				}
				else if (i==N-1) {
					if (B[i-1]) ans.push_back(V[i]);
				}
				else {
					if (B[i-1] || B[i+1]) ans.push_back(V[i]);
				}
			}
		}
	}

	sort(ans.begin(),ans.end());
	for (int i=0; i<ans.size(); i++) {
		if (i==0) cout << ans[i] << endl;
		else {
			if (ans[i]!=ans[i-1]) cout << ans[i] << endl;
		}
	}

}