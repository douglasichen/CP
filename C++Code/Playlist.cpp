#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];

	int ans=0;
	map<int,bool> has;
	int l=0,r=0;
	for (; r<N; r++) {
		if (has[V[r]]) {
			while (has[V[r]]) {
				has[V[l]]=0;
				l++;
			}
			has[V[r]]=1;
		}
		else {
			has[V[r]]=1;
		}
		ans=max(ans,r-l+1);
	}
	cout << ans << endl;
}