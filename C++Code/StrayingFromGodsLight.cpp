#include <bits/stdc++.h>
using namespace std;

int N;
char V[1000][1000];
long long ans=0;

vector<vector<int>> dirs = {
	{1,0},
	{0,-1},
	{0,1},
};

vector<int> add(vector<int> a, vector<int> b) {
	return {a[0]+b[0], a[1]+b[1]};
}

char val(vector<int> p) {
	return V[p[0]][p[1]];
}

void cSet(vector<int> p, char c) {
	V[p[0]][p[1]]=c;
}

bool inBounds(vector<int> p) {
	return p[0]>=0 && p[0]<=N-1 && p[1]>=0 && p[1]<=N-1;
}

void solve() {
	vector<int> start={0,0}, goal={N-1,N-1};
	deque<pair<vector<int>,vector<int>>> dq;
	dq.push_back({start,{0,0,0}});	// loc, data (d,l,r)
	cSet(start, '#');

	bool fnd=0;
	while (!dq.empty()) {
		pair<vector<int>, vector<int>> back=dq.back(); dq.pop_back();
		vector<int> fLoc=back.first, fData=back.second;
		
		if (fLoc==goal) {
			for (int i=0; i<3; i++) ans+=((long long)fData[i]*(long long)fData[i]);
			fnd=1;
			break;
		}

		for (int i=0; i<3; i++) {
			vector<int> dir=dirs[i], nLoc=add(fLoc,dir), nData=fData;
			nData[i]++;
			if (inBounds(nLoc) && val(nLoc)!='#') {
				dq.push_front({nLoc,nData});
				cSet(nLoc,'#');
			}
		}
	}
	if (!fnd) ans=-1;

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	for (int y=0; y<N; y++) {
		for (int x=0; x<N; x++) {
			cin>>V[y][x];
		}
	}
	solve();
	cout << ans << endl;
}