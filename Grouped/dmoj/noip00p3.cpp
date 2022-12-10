#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int N;
vector<string> V;
char init;

int ans=0;
void solve(vector<int> done, string S) {
	// cout << S << endl;
	ans=max(ans, (int)S.size());
	
	
	for (int at=0; at<N; at++) {
		if (S.size()) {
			if (done[at]==2) continue;

			map<string,bool> pre;
			string s="";
			for (int i=0; i<V[at].size()-1; i++)
				s+=V[at][i],
				pre[s]=1;
			for (int o=S.size()-1; o>0; o--) {
				string mid=S.substr(o, S.size()-o);
				if (mid.size()>=V[at].size()) break;
				if (pre[mid]) {
					string nS=S+V[at].substr(mid.size(), V[at].size()-mid.size());
					vector<int> nDone=done;
					nDone[at]++;
					solve(nDone, nS);
					break;
				}
			}
		}
		else {
			if (V[at][0]!=init) continue;
			vector<int> nDone=done;
			nDone[at]=1;
			solve(nDone, V[at]);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	V=vector<string>(N);
	for (int i=0; i<N; i++) cin>>V[i]; cin>>init;
	vector<int> done(8);
	solve(done, "");
	cout << ans << endl;
}