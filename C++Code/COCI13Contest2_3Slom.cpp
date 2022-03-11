#include <bits/stdc++.h>
using namespace std;

string rep(int N, string S) {
	string T;
	for (int i=0; i<N; i+=2) T+=S[i];
	for (int i=N-1-(N%2); i>=0; i-=2) T+=S[i];
	return T;
}

hash<string> h;


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cout << h(E) << endl;
	
	int X; cin>>X;
	string S; cin>>S;
	int N=S.size();

	// X%=(N+(N%2 ? 1 : -1));

	


	for (int i=0; i<X; i++) {
		S=rep(N,S);
	}
	cout << S << endl; 
}

