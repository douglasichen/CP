#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	vector<int> C(4);
	for (int i=0; i<4; i++) cin>>C[i];
	string s; cin>>s;
	int sz=s.size();
	long long ans=0;
	for (char c : s) {
		c-='0';
		ans+=C[c-1];
	}
	cout << ans << endl;
}