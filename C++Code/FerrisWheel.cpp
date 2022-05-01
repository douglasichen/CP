#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,W; cin>>N>>W;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];	
	sort(V.begin(),V.end());

	int ans=0;
	int i=0,j=N-1;
	while (i<=j) {
		if (i==j) {
			ans++;
			break;
		}
		else {
			if (V[i]+V[j]>W) {
				ans++;
				j--;
			}
			else {
				i++; j--;
				ans++;
			}
		}
	}
	cout << ans << endl;
}