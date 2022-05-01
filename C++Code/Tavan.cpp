#include <bits/stdc++.h>
using namespace std;

int N,M,K,X;
string S;
vector<string> V;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M>>K>>X>>S;
	vector<vector<int>> valMap(M,vector<int>(K));
	V=vector<string>(M);
	for (int i=0; i<M; i++) {
		cin>>V[i];
		sort(V[i].begin(), V[i].end());
	}

	int j=0;
	for (int y=M-1; y>=0; y--) {
		for (int x=0; x<K; x++) {
			int i=x+1;
			valMap[y][x]=i*pow(K,j);
			if (valMap[y][x]>=1e9) break;
		}
		j++;
	}

	for (int y=0; y<M; y++) {
		for (int x=0; x<K; x++) {
			cout << valMap[y][x] << ' ';
		}
		cout << endl;
	}


	string ans="";
	for (int y=0; y<M; y++) {
		for (int x=0; x<K; x++) {
			if (valMap[y][x]>=X) {
				ans+=V[y][x];
				int subI=x-1;
				int sub;
				if (subI<0) sub=0;
				else sub=valMap[y][x-1];
				X-=sub;
				break;
			}
		}
	}

	// works
	int l=0;
	string aa="";
	for (int i=0; i<N; i++) {
		if (S[i]=='#') {
			aa+=ans[l];
			l++;
		}
		else aa+=S[i];
	}
	cout << aa << endl;

}