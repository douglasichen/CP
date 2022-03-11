#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> V;

void solve() {
	if (N==1) {
		cout << V[0] << endl << "E" << endl;
		return;
	}
	vector<int> A;
	int b=0,s=N-1;
	string ans="";
	while (b<s) {
		A.push_back(V[b]);
		A.push_back(V[s]);
		b++;
		s--;
		ans+="BS";
	}
	if (b==s) {
		ans+="E";
		A.push_back(V[b]);
	}
	
	// print
	for (int i=0; i<N; i++) {
		cout << A[i] << (i<N-1 ? " " : "");
	}
	cout << endl;
	cout << ans << endl;
}

int main() {
	cin>>N;
	for (int i=0; i<N; i++) {
		int inp; cin>>inp;
		V.push_back(inp);
	}
	sort(V.begin(), V.end());
	solve();
}