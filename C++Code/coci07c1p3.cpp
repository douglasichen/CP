#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,A,B; cin>>N;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i]; sort(V.begin(),V.end());
	cin>>A>>B;
	vector<int> ans={-1,0};
	for (int i=1; i<N; i++) {
		int mid=(V[i]+V[i-1])/2;
		if (mid-1<A) mid+=(mid%2==0);
		else mid-=(mid%2==0);
		if (mid<A) mid=A+(A%2==0);
		if (mid>B) mid=B-(B%2==0);
		int dif=min(mid-V[i-1],V[i]-mid);
		if (dif>ans[1]) ans={mid,dif};
	}
	A+=(A%2==0); B-=(B%2==0);
	int L=V.front()-A,R=B-V.back();
	if (L>ans[1]) ans={A,L};
	if (R>ans[1]) ans={B,R};
	cout << ans[0] << '\n';
}