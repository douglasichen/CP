#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<vector<vector<int>>> g;
vector<int> dv;
vector<int> sv;
vector<int> ans;

void solve() {

}

int main() {
	cin>>n>>k;
	g = *(new vector<vector<vector<int>>>(n+1));
	dv = *(new vector<int>(n+1));
	sv = *(new vector<int>(k+1));
	ans = *(new vector<int>(n+1));

	vector<vector<int>> data(n);
	for (int i=1; i<=n-1; i++) {
		int a,b,d; cin>>a>>b>>d;
		data[i]={a,b,d};
	}
	for (int i=1; i<=k; i++) {
		cin>>sv[i];
	}
	
	solve();

	for (int i=1; i<=n; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}