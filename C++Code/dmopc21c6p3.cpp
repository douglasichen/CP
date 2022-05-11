#include <bits/stdc++.h>
using namespace std;

int N,M,K;
vector<vector<int>> V,D;
deque<vector<int>> dq;

bool inBnd(vector<int> p) {
	return p[0]>=0 && p[0]<N && p[1]>=0 && p[1]<M;
}

vector<int> add(vector<int> a, vector<int> b) {
	return {a[0]+b[0],a[1]+b[1]};
}

int val(vector<vector<int>> &S, vector<int> p) {
	return S[p[0]][p[1]];
}

void upt(vector<vector<int>> &S, vector<int> p, int val) {
	S[p[0]][p[1]]=val;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M>>K;
	V=vector<vector<int>>(N,vector<int>(M));
	D=vector<vector<int>>(N,vector<int>(M,1e9));
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			cin>>V[y][x];
			if (V[y][x]) {
				dq.push_back({y,x});
				D[y][x]=0;
			}
		}
	}
	vector<vector<int>> dirs={
		{0,1},
		{1,0},
		{-1,0},
		{0,-1}
	};
	while (!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();
		for (vector<int> dir : dirs) {
			vector<int> nxt=add(back,dir);
			if (inBnd(nxt)) {
				int dis=val(D,nxt), nDis=val(D,back)+1;
				if (nDis>K) continue;
				if (nDis<dis) {
					upt(D,nxt,nDis);
					dq.push_front(nxt);
					upt(V,nxt,val(V,back));
				}
				else if (nDis==dis) {
					if (val(V,back)<val(V,nxt)) {
						upt(V,nxt,val(V,back));
						dq.push_front(nxt);
					}
				}
			}
		}
	}
	for (vector<int> v : V) {
		for (int i : v) cout << i << ' ';
		cout << endl;
	}
}