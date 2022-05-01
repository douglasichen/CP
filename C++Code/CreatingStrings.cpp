#include <bits/stdc++.h>
using namespace std;

string S;
int N;
unordered_map<string,bool> has;
vector<string> ans;

hash<string> h;

void solve(string s, vector<bool> taken) {
	if (s.size()==N) {
		if (!has[s]) {
			ans.push_back(s);
			has[s]=1;
		}
		return;
	}
	for (int i=0; i<N; i++) {
		if (taken[i]) continue;
		string ns=s; vector<bool> nTaken=taken;
		ns+=S[i];
		nTaken[i]=1;
		solve(ns,nTaken);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>S;
	N=S.size();
	solve("",vector<bool>(N));

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (string s : ans) cout << s << endl;
}