#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


void solve() {

}

bool sorter (vi a, vi b) {
	return a[3] < b[3];
}

bool compDim(vi a, vi b) {
	for (int i=0; i<3; i++) {
		if (a[i]>b[i]) return false;
	}
	return true;
}

int main() {
	vector<vi> dims;
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		vi dim(3);
		cin>>dim[0]>>dim[1]>>dim[2];
		sort(dim.begin(), dim.end());
		dim.PB(dim[0]*dim[1]*dim[2]);
		dims.PB(dim);
	}
	sort(dims.begin(), dims.end(), sorter);
	
	int m; cin>>m;
	for (int i=0; i<m; i++) {
		vi iDim(3);
		cin>>iDim[0]>>iDim[1]>>iDim[2];
		sort(iDim.begin(), iDim.end());
		iDim.PB(iDim[0]*iDim[1]*iDim[2]);
		int vol = iDim[3];

		bool found = false;
		int ans = 0;
		for (int j=0; j<dims.size(); j++) {
			vi dim = dims[j];
			int pVol = dim[3];
			if (vol <= pVol) {
				if (compDim(iDim, dim)) {
					ans = pVol;
					found = true;
					break;
				}
			}
		}
		if (!found) {
			cout<<"Item does not fit."<<endl;
		}
		else {
			cout<<ans<<endl;
		}
	}
}