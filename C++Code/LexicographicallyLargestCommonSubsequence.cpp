#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin>>N;
	vector<string> V(N);

	for (int i=0; i<N; i++) {
		cin>>V[i];
	}
	sort(V.begin(), V.end(), greater<string>());
	char cur='z';
	while (cur>='a') {
		for (int i=N-1; i>=0; i--) {
			
			cur--;
		}
	}
}