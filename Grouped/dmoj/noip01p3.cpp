#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int P,K,D,N; cin>>P>>K;
	string s,S="";
	while (P--) cin>>s, S+=s;
	N=S.size();

	cin>>D;
	vector<string> dict(D);
	for (int i=0; i<D; i++) cin>>dict[i];
	sort(dict.begin(), dict.end());
	
	vector<int> A(N+1);
	for (int i=0; i<N; i++) {
		for (string &d : dict) {
			if (i+d.size()<=N && S.substr(i,d.size())==d) {
				A[i+1]=d.size();
				break;
			}
		}
	}
	vector<vector<int>> dp(K+1, vector<int>(N+1));
	for (int i=1; i<=N; i++)
		
		
}