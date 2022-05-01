#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S; cin>>S;
	int K,N=S.size(); cin>>K;
	vector<string> V;

	for (int i=0; i<N-K; i++) {
		string s="";
		for (int j=i; j<N; j++) {
			s+=S[j];
			if (s.size()>=K) V.push_back(s);
		}
	}

	sort(V.begin(),V.end());

	cout << V[0] << endl;
}