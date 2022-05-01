#include <bits/stdc++.h>
using namespace std;

int N;
long long K;
vector<int> V,A,past;

bool done=0;

void solve(int level) {
	past=A;
	for (int i=1; i<=N; i++) {
		A[V[i]]=past[i];
	}
	if (!done) {
		if (A==V) {
			// cout << "level: " << level << endl;
			K%=level;
			done=1;
		}
	}
}

void p() {
	for (int o=1; o<=N; o++) cout << A[o] << " ";
	cout << endl;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>K;
	
	V=vector<int>(N+1);
	for (int i=1; i<=N; i++) cin>>V[i];
	A=V;

	for (int i=1; i<=K; i++) {
		solve(i);
	}
	p();
	
}