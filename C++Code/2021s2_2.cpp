#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	
	int n,m,k; cin>>n>>m>>k;

	vector<bool> rowData(n+1), colData(m+1);

	
	for (int i=0; i<k; i++) {
		char c; cin>>c;
		int l; cin>>l;
		if (c=='R') {
			rowData[l]=!rowData[l];
		}
		else {
			colData[l]=!colData[l];
		}
	}

	int ans=0;
	int rows=0;
	for (int r : rowData) {
		if (r) {
			ans+=m;
			rows++;
		}
	}

	for (int cl : colData) {
		if (cl) {
			ans-=rows*2;
			ans+=n;
		}
	}


	cout << ans << endl;
}