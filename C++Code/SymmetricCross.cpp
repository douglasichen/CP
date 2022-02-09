#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<bool>> g;

unordered_map<int,bool> workedFor;
unordered_map<int,pair<int,int>> wfData;

vector<vector<int>> dirs={
	{1,0},
	{0,1},
	{-1,0},
	{0,-1},
};

vector<int> addVec(vector<int> a, vector<int> b) {
	return {a[0]+b[0], a[1]+b[1]};
}

vector<int> mult(vector<int> a, int b) {
	return {a[0]*b, a[1]*b};
}

bool good(int y, int x, int k) {
	// vector<bool> right, compare;
	// for (int i=x+1; i<=x+k; i++)
	// 	right.push_back(g[y][i]);
	// for (int i=x-1; i>=x-k; i--) {
	// 	compare.push_back(g[y][i]);
	// 	int index=compare.size()-1;
	// 	if (compare[index]!=right[index])
	// 		return false;
	// }
	// compare.clear();
	// for (int i=y-1; i>=y-k; i--) {
	// 	compare.push_back(g[i][x]);
	// 	int index=compare.size()-1;
	// 	if (compare[index]!=right[index])
	// 		return false;
	// }
	// compare.clear();
	// for (int i=y+1; i<=y+k; i++) {
	// 	compare.push_back(g[i][x]);
	// 	int index=compare.size()-1;
	// 	if (compare[index]!=right[index])
	// 		return false;
	// }


	for (int i=1; i<=k; i++) {
		bool ok=1;
		vector<int> d=addVec({y,x}, mult(dirs[0],i));
		for (vector<int> dir : dirs) {
			vector<int> newD=addVec({y,x}, mult(dir,i));
			// for (int i : newD) cout << i << ' ';
			// cout << endl;
			if (g[d[0]][d[1]]!=g[newD[0]][newD[1]]) {
				ok=0;
				break;
			}
		}
		if (ok) {
			workedFor[i]=true;
			wfData[i]={y,x};
		}
		else {
			// cout << endl;
			return false;
		}
	}
	// cout << endl;
	return true;
}

pair<int,int> works(int k) {
	if (k==0) return {0,0};
	if (workedFor[k]) return wfData[k];
	// cout << "k=" << k << endl;
	pair<int,int> start={k,k};
	for (int y=start.first; y<n-k; y++) {
		for (int x=start.first; x<m-k; x++) {
			if (good(y,x,k))
				return {y,x};
		}
	}
	return {-1,-1};
}

void solve(int maxK) {

	// for (int i=0; i<=maxK; i++) {
	// 	pair<int,int> t=works(i);
	// 	cout << t.first << " " << t.second << endl;
	// }
	// return;

	pair<int,int> loc=works(maxK);
	if (loc.first!=-1) {
		cout << maxK << ' ' << loc.first+1 << ' ' << loc.second+1 << endl;
		return;
	}
	int left=0, right=maxK;
	
	while (left+1<right) {
		int mid = (left+right)/2;
		pair<int,int> newLoc=works(mid);
		if (newLoc.first==-1) {
			right=mid;
		}
		else {
			left=mid;
			loc=newLoc;
		}
		// if (abs(right-left)<=1) break;
	}
	cout << left << ' ' << loc.first+1 << ' ' << loc.second+1 << endl;

	// int ans=0;
	// pair<int,int> loc;
	// for (int i=maxK; i>=0; i--) {
	// 	loc=works(i);	
	// 	if (loc.first!=-1) {
	// 		ans=i;
	// 		break;
	// 	}
	// }
	// cout << ans << ' ' << loc.first+1 << ' ' << loc.second+1 << endl;
}

int main() {
	cin>>n>>m;
	g = *(new vector<vector<bool>>(n, *(new vector<bool>(m))));
	for (int y=0; y<n; y++) {
		for (int x=0; x<m; x++) {
			int i; cin>>i;
			g[y][x]=(bool)i;
		}
	}
	int maxK=min(n,m);
	if ((maxK&1)!=1) {
		maxK-=2;
		maxK/=2;
	}
	else {
		maxK-=1;
		maxK/=2;
	}

	solve(maxK);
}