#include <bits/stdc++.h>
using namespace std;

bool solve(int N, vector<int> V) {
	int a=0,b=0;
	for (int i=1; i<N; i++) {
		int dif=V[i]-V[i-1]-1;
		if (dif>2) return 0;
		if (dif==2) b++;
		else if (dif==1) a++;
	}
	if (a==0) {
		return b<=1;
	}
	return b==0 && a<=2;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	for (int i=0,N; i<T; i++) {
		cin>>N;
		vector<int> V(N);
		for (int o=0; o<N; o++) cin>>V[o];
		cout << (solve(N,V) ? "YES" : "NO") << endl;
	}	
}