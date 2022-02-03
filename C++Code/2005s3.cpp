#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<vector<long long>>> mats;

void solve() {

}

void printMat(vector<vector<long long>> mat) {
	for (vector<long long> row : mat) {
		for (long long i : row) cout << i << ' ';
		cout << endl;
	}
}

vector<vector<long long>> multMat(vector<vector<long long>> a, vector<vector<long long>> b) {
	int r = a.size()*b.size(), c = a[0].size()*b[0].size();
	vector<vector<long long>> ans(r,*(new vector<long long>(c)));
	
	for (int ay=0; ay<a.size(); ay++) {
		for (int ax=0; ax<a[0].size(); ax++) {
			for (int by=0; by<b.size(); by++) {
				for (int bx=0; bx<b[0].size(); bx++) {
					int y=ay*b.size()+by, x=ax*b[0].size()+bx;
					// cout << y << ' ' << x << endl; 
					ans[y][x] = a[ay][ax] * b[by][bx];
				}
			}
		}
	}
	return ans;
}


int main() {
	cin>>n;
	mats = *(new vector<vector<vector<long long>>>(n));
	for (int i=0; i<n; i++) {
		int r,c; cin>>r>>c;
		vector<vector<long long>> mat(r, *(new vector<long long>(c)));
		for (int y=0; y<r; y++) {
			for (int x=0; x<c; x++) {
				cin>>mat[y][x];
			}
		}
		mats[i]=mat;
	}
	vector<vector<long long>> ansMat = mats[n-1];
	for (int i=n-1; i>0; i--) {
		vector<vector<long long>> matB = ansMat, matA = mats[i-1];
		ansMat = multMat(matA, matB);
	}
	// printMat(ansMat);

	// init
	long long a=ansMat[0][0],b=ansMat[0][0],c=0,d=0,e=0,f=0;
	for (int x=0; x<ansMat[0].size(); x++) c+=ansMat[0][x];
	d=c;
	for (int y=0; y<ansMat.size(); y++) e+=ansMat[y][0];
	f=e;

	for (int y=0; y<ansMat.size(); y++) {
		long long rSum=0;
		for (int x=0; x<ansMat[0].size(); x++) {
			long long k=ansMat[y][x];
			a = max(a,k);
			b = min(b,k);
			rSum+=k;
		}
		c = max(c,rSum);
		d = min(d,rSum);
	}
	for (int x=0; x<ansMat[0].size(); x++) {
		long long cSum=0;
		for (int y=0; y<ansMat.size(); y++) {
			cSum+=ansMat[y][x];
		}
		e = max(e,cSum);
		f = min(f,cSum);
	}
	cout << a << endl << b << endl << c << endl << d << endl << e << endl << f << endl;
}