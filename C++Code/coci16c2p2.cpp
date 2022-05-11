#include <bits/stdc++.h>
using namespace std;

int N,M;
long long K,X;
vector<long long> PW;
vector<string> OP;
vector<char> ans;
string S;

void rec(int I, long long start, int H) {
	if (H==1) {
		ans[I]=OP[I][X-start];
		return;
	}
	long long A=start;
	for (int i=0; i<K; i++) {
		long long B=(long long)(start-1)+PW[H-1]*(i+1);
		if (X<=B) {
			ans[I]=OP[I][i];
			rec(I+1,A,H-1);
			return;
		}
		A=B+1;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M>>K>>X>>S;
	PW=vector<long long>(M+1,1);
	for (int i=1; i<=M; i++) {
		PW[i]=PW[i-1]*K;
		if (PW[i]>=1e9) break;
	}
	OP=vector<string>(M);
	ans=vector<char>(M);
	for (int i=0; i<M; i++) cin>>OP[i],sort(OP[i].begin(),OP[i].end());
	rec(0,1,M);

	int a=0;
	for (int i=0; i<N; i++) {
		if (S[i]=='#') {
			S[i]=ans[a];
			a++;
		}
	}
	cout << S << endl;
}