#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans=0;
	int N,T; cin>>N>>T;
	vector<vector<int>> V(T+2,vector<int>(2));
	for (int i=1; i<=T; i++) cin>>V[i][0]>>V[i][1];
	V[T+1]={N+1,N+1};
	sort(V.begin(),V.end());	
	for (int a=0; a<T+1; a++) {
		int y1=V[a][0];
		for (int b=a+1; b<T+2; b++) {
			int y2=V[b][0],H=y2-1-y1;
			vector<int> xs={0,N+1};
			for (int c=a+1; c<b; c++) xs.push_back(V[c][1]);
			sort(xs.begin(),xs.end());
			for (int i=1; i<xs.size(); i++) {
				int W=xs[i]-1-xs[i-1];
				ans=max(ans,min(W,H));
			}
		}
	}
	cout << ans << endl;
}