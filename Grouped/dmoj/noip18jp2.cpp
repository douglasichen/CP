#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N+1);
	for (int i=1; i<=N; i++) cin>>V[i];
	int M,P1,S1,S2; cin>>M>>P1>>S1>>S2;
	V[P1]+=S1;
	
	int A=0, B=0;
	for (int i=1; i<M; i++) A+=V[i];
	for (int i=M+1; i<=N; i++) B+=V[i];
	vector<int> ans={abs(A-B),M}; // dif, spot
	
	for (int i=1; i<=N; i++) {
		if (i<M) {
			int dif=abs(A+S2-B);
			if (dif<ans[0]) ans={dif,i};
		}
		else if (i>M) {
			int dif=abs(A-(B+S2));
			if (dif<ans[0]) ans={dif,i};
		}
	}
	cout << ans[1] << endl;
}