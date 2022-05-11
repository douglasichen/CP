#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	string S; cin>>S;
	vector<int> V(M),loc(M);
	int k=0;
	for (int i=0; i<N; i++) if (S[i]=='0') loc[k]=i,k++;
	for (int i=0; i<M; i++) cin>>V[i];
	int mx=0,start=0;
	for (int i : V) mx=max(i,mx);
	for (int i=0; i<M; i++) if (V[i]==mx) start=loc[i];
	string ans="";
	for (int i=start; i<N; i++) if (S[i]!='0') ans+=S[i];
	for (int i=0; i<start; i++) if (S[i]!='0') ans+=S[i];
	cout << ans << endl;
}