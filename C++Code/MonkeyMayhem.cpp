#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	unordered_map<int,bool> rowsHas, colsHas;
	int n,m; cin>>n>>m;
	vector<int> rows(n),cols(m);
	for (int i=0; i<n; i++) {
		cin>>rows[i];
		if (rows[i]!=-1) rowsHas[rows[i]]=1;
	}
	for (int i=0; i<m; i++) {
		cin>>cols[i];
		if (cols[i]!=-1) colsHas[cols[i]]=1;
	}

	int ans=0;
	for (int r : rows) {
		if (colsHas[r]) ans++;
	}
	// for (int c : rows) {
	// 	if (rowsHas[c]) ans++;
	// }
	cout << ans << endl;
}