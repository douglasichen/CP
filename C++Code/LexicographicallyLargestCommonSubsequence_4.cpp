#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N; cin>>N;
	vector<string> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	
	vector<vector<int>> has(N,vector<int>('z'+1));
	for (int i=0; i<N; i++) {
		for (char c : V[i]) {
			has[i][c]++;
		}
	}


	vector<int> starts(N);
	string ANS="";
	for (char look='z'; look>='a';) {
		bool good=1;
		vector<int> nStarts=starts;
		vector<vector<int>> nHas=has;
		for (int i=0; i<N; i++) {
			if (has[i][look]) {
				string s=V[i];
				int sz=s.size();
				for (int j=starts[i]; j<sz; j++) {
					nHas[i][s[j]]--;
					if (s[j]==look) {
						nStarts[i]=j+1;
						break;
					}
				}
			}
			else {
				good=0;
				break;
			}
		}
		if (good) {
			ANS+=look;
			starts=nStarts;
			has=nHas;
		}
		else look--;
	}
	cout << (ANS.size()>0 ? ANS : "-1") << endl;
}