#include <bits/stdc++.h>
using namespace std;

bool sorter(string a, string b) {
	return a+b>b+a;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N; cin>>N;
	vector<string> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	sort(V.begin(), V.end(), sorter);
	for (string s : V) cout << s;
	cout << endl;
}