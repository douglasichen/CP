#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> INDS;
vector<string> V;


int ind=0;
bool sorter(int i, int j) {
	if (V[ind][i]==V[ind][j]) return i<j;
	else return V[ind][i]>V[ind][j];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	INDS=vector<vector<int>>(N);
	V=vector<string>(N);

	for (int i=0; i<N; i++) {
		cin>>V[i];

		int sz=V[i].size();	
		vector<int> inds(sz);
		for (int o=0; o<sz; o++) inds[o]=o;
		INDS[i]=inds;
	}
	for (int i=0; i<N; i++) {
		sort(INDS[i].begin(), INDS[i].end(), sorter);
		ind++;
	}

	for (int i=0; i<N; i++) {
		int sz=V[i].size();
		string s=V[i];
		for (int o=0; o<sz; o++) {
			cout << s[INDS[i][o]];
		}
		cout << endl;
	}
	
}