#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N; cin>>N;
	bitset<'z'+1> ah;
	string V[N];
	for (int i=0; i<N; i++) {
		cin>>V[i];
		bitset<'z'+1> h;
		for (char c : V[i]) h[c]=1;
		if (i==0) ah=h;
		else ah&=h;
	}
	
	string ans="";
	char cur='z';
	vector<int> starts(N);
	while (cur>='a') {
		if (!ah[cur]) {
			cur--;
			continue;
		}
		bool fnd=0;
		vector<int> nStarts=starts;
		for (int i=0; i<N; i++) {
			fnd=0;
			string s=V[i];
			for (int o=starts[i]; o<s.size(); o++) {
				if (s[o]==cur) {
					fnd=1;
					nStarts[i]=o+1;
					break;
				}
			}
			if (!fnd) break;
		}
		if (!fnd) {
			cur--;
		}
		else {
			starts=nStarts;
			ans+=cur;
		}
	}
	if (ans.size()==0) cout << -1 << endl;
	else cout << ans << endl;
}