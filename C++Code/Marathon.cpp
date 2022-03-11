#include <bits/stdc++.h>
using namespace std;

const int MX_N=500000, MX_LOG=19;
int N,Q, ST[MX_N][MX_LOG+1], V[MX_N];

void pre() {
	for (int e=1; e<=MX_LOG; e++) {
		int mxI=N-(1<<e), e2=e-1, half=(1<<e2);
		for (int i=0; i<=mxI; i++) {
			ST[i][e]=ST[i][e2]+ST[i+half][e2];
		}
	}
}

int sum(int a, int b) {
	int ans=0;
	int size=b-a+1;
	int i=a, e=0;
	while (size) {
		if (size&1) {
			ans+=ST[i][e];
			i+=(1<<e);
		}
		size>>=1;
		e++;
	}
	return ans;
}

int main() {
	int mxSum=0;
	cin>>N>>Q;
	for (int i=0; i<N; i++) {
		cin>>V[i];
		mxSum+=V[i];
		ST[i][0]=V[i];
	}
	pre();
	int ans[Q];

	for (int i=0; i<Q; i++) {
		int a,b; cin>>a>>b; a--; b--;
		ans[i]=mxSum-sum(a,b);
	}

	for (int i=0; i<Q; i++) {
		cout << ans[i] << endl;
	}
}