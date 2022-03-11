#include <bits/stdc++.h>
using namespace std;

int N,K,Q;
int KS[5000][2][2];
// vector<vector<vector<int>>> KS(5001);


long long val(vector<int> p) {
	return (long long)(p[0]-1)*(long long)N+(long long)p[1];
}

bool inBounds(vector<int> src, int bnds[][2]) {
	int y=src[0], x=src[1];
	int minY=bnds[0][0], maxY=bnds[1][0], minX=bnds[0][1], maxX=bnds[1][1];
	return y>=minY && y<=maxY && x>=minX && x<=maxX;

	// return src[0]>=bnds[0][0] && src[0]<=bnds[1][0] && src[1]>=bnds[0][1] && src[1]<=bnds[1][1];
}

vector<int> add(int a[], vector<int> b) {
	return {a[0]+b[0], a[1]+b[1]};
}

vector<int> sub(int a[], vector<int> b) {
	return {a[0]-b[0], a[1]-b[1]};
}

vector<int> add(vector<int> a, vector<int> b) {
	return {a[0]+b[0], a[1]+b[1]};
}

vector<int> sub(vector<int> a, vector<int> b) {
	return {a[0]-b[0], a[1]-b[1]};
}


vector<vector<int>> data(5001);

vector<int> rot(vector<int> p, int i) {
	vector<int> dis, nPos, orig;
	int half=data[i][1];
	int r=data[i][2];
	orig=add(KS[i][0],{half,half});

	if (r==0) {
		if (p[0]>=orig[0]) orig[0]--;
		if (p[1]>=orig[1]) orig[1]--;
	}
	dis=sub(p,orig);
	int y=dis[0], x=dis[1];
	dis={-x,y};
	
	// reset
	orig=add(KS[i][0],{half,half});
	if (r==0) {
		if (dis[0]>0) orig[0]--;
		if (dis[1]>0) orig[1]--;
	}
	nPos=add(orig,dis);

	return nPos;
}

vector<int> solve(vector<int> p) {
	// start from last K Elem
	for (int i=K-1; i>=0; i--) {
		if (inBounds(p,KS[i])) {
			vector<int> rotLoc=rot(p,i);
			p=rotLoc;
		}
	}
	return p;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>K>>Q;
	for (int i=0; i<K; i++) {
		// int a,b,c,d; cin>>a>>b>>c>>d;
		// KS[i]={{a,b},{c,d}};
		cin>>KS[i][0][0]>>KS[i][0][1]>>KS[i][1][0]>>KS[i][1][1];

		// data
		int len=KS[i][1][0]-KS[i][0][0]+1;
		int half=len/2;
		int r=len%2;
		data[i]={len,half,r};
	}

	string s="";
	for (int i=0; i<Q; i++) {
		int a,b; cin>>a>>b;
		vector<int> loc=solve({a,b});
		s+=to_string(val(loc)) + "\n";
	}
	cout << s;
}