#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("circlecross.in","r",stdin); 
	freopen("circlecross.out","w",stdout); 

	vector<vector<int>> m('Z'+1,vector<int>(2,-1));
	for (int i=0; i<52; i++) {
		char c; cin>>c;
		if (m[c][0]==-1) m[c][0]=i;
		else m[c][1]=i;
	}
	int ans=0;
	for (char a='A'; a<='Y'; a++) {
		for (char b=a+1; b<='Z'; b++) {
			ans+=m[a][0]<m[b][0] && m[a][1]<m[b][1] && m[a][1]>m[b][0] || m[a][0]>m[b][0] && m[a][0]<m[b][1] && m[a][1]>m[b][1];
		}
	}
	cout << ans << endl;
}