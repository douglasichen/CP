#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	map<int,int> M;
	for (int i=0; i<N; i++) {
		int a,b; cin>>a>>b;
		M[a]=1;
		M[b]=-1;
	}
	int ans=0, ppl=0;
	for (map<int,int>::iterator i=M.begin(); i!=M.end(); i++) {
		ppl+=i->second;
		ans=max(ans,ppl);
	}
	cout << ans << endl;
}