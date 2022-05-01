#include <bits/stdc++.h>
using namespace std;

int N,Q;
vector<int> V;
vector<int> D;

void add(int l, int r, int x) {
	V[l]+=x;
	V[r+1]-=x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>Q;
	V=vector<int>(N);
	D=vector<int>(N+1);
	for (int i=0; i<N; i++) {
		cin>>V[i];
		if (i==0) D[i]=V[i];
		else D[i]=V[i]+V[i-1];
	}
	for (int i=0; i<Q; i++) {
		int a,b,x; cin>>a>>b>>x;
		add(a,b,x);
	}
	apply();
	for (int i : V) cout << i << ' ';
	cout << endl;
}