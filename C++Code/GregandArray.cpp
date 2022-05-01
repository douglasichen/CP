#include <bits/stdc++.h>
using namespace std;

int N,M,K;
vector<unsigned long long> V,dif;
vector<int> mult;
vector<vector<unsigned long long>> dta;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M>>K;
	V=vector<unsigned long long>(N);
	dif=vector<unsigned long long>(N+1);
	mult=vector<int>(M+1);
	dta=vector<vector<unsigned long long>>(M,vector<unsigned long long>(3));
	for (int i=0; i<N; i++) cin>>V[i];
	for (int i=0; i<M; i++) {
		cin>>dta[i][0]>>dta[i][1]>>dta[i][2];
		dta[i][0]--; dta[i][1]--;
	}
	for (int i=0; i<K; i++) {
		int x,y; cin>>x>>y; x--; y--;
		mult[x]++; mult[y+1]--;
	}
	// fully compute mult now
	for (int i=1; i<M; i++) {
		mult[i]+=mult[i-1];
	}
	for (int i=0; i<M; i++) {
		int l=dta[i][0], r=dta[i][1];
		if (mult[i]<=0) continue;
		unsigned long long x=dta[i][2], add=x*mult[i];
		dif[l]+=add;
		dif[r+1]-=add;
	}
	for (int i=1; i<N; i++) {
		dif[i]+=dif[i-1];
	}
	for (int i=0; i<N; i++) {
		V[i]+=dif[i];
	}
	for (unsigned long long i : V) cout << i << ' ';
	cout << endl;
}