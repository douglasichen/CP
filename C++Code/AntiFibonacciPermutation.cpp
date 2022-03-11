#include <bits/stdc++.h>
using namespace std;

void print(vector<int> V) {
	for (int i=1; i<V.size(); i++) {
		cout << V[i] << ' ';
	}
	cout << endl;
}

void solve(int N) {
	vector<int> V(N+1);
	for (char i=1; i<=N; i++) {
		V[i]=i;
	}

	for (int i=4; i<=N; i++) {
		swap(V[3],V[i]);
		print(V);
		swap(V[3],V[i]);
	}
	if (N==3) {
		cout << 3 << ' ' << 2 << ' ' << 1 << ' ' << endl << 1 << ' ' <<  3 << ' ' << 2 << endl << 3 << ' ' << 1 << ' ' << 2 << endl;
	}
	else {
		for (int i=1; i<=2; i++) {
			swap(V[i],V[N]);
			print(V);
			swap(V[i],V[N]);
		}
		for (int i=N; i>0; i--) cout << V[i] << ' '; cout << endl;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	for (int i=0; i<T; i++) {
		int N; cin>>N;
		solve(N);
	}
}