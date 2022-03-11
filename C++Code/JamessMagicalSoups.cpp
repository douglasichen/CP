#include <bits/stdc++.h>
using namespace std;

int N,X;
vector<vector<int>> V;

bool sorter(vector<int> a, vector<int> b) {
	return a[1]<b[1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>X>>N;
	for (int i=0; i<N; i++) {
		int T,F; cin>>T>>F;
		V.push_back({T,F});
	}
	sort(V.begin(), V.end(), sorter);
	
	int t=0;
	for (int i=0; i<N; i++) {
		int T=V[i][0], F=V[i][1];
		if (T>F) continue;
		int wait=min(T-X,);
	}
}