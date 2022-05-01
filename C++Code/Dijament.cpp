#include <bits/stdc++.h>
using namespace std;

int N,M,ANS=0;
bool V[2000][2000];
bool DONE[2000][2000];

const vector<vector<int>> dirs={
	{1,0},{-1,0},{0,1},{0,-1}
};

string v2s(vector<int> v) {
	return "(" + to_string(v[0]) + "," + to_string(v[1]) + ")";
}

bool val(vector<int> v) {
	return V[v[0]][v[1]];
}

bool inBound(vector<int> v) {
	return v[0]>=0 && v[0]<N && v[1]>=0 && v[1]<M;
}

bool isDone(vector<int> v) {
	return DONE[v[0]][v[1]];
}

vector<int> add(vector<int> a, vector<int> b) {
	return {a[0]+b[0],a[1]+b[1]};
}

void setVal(bool b, vector<int> pos, vector<vector<bool>> &v) {
	v[pos[0]][pos[1]]=b;
}

bool valAt(vector<int> pos, vector<vector<bool>> &vis) {
	return vis[pos[0]][pos[1]];
}

void setDone(bool b, vector<int> pos) {
	DONE[pos[0]][pos[1]]=b;
}

void printV(vector<vector<bool>> v) {
	for (int y=0; y<v.size(); y++) {
		for (int x=0; x<v[0].size(); x++) {
			cout << v[y][x];
		}
		cout << endl;
	}
}

void printDone() {
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			cout << DONE[y][x];
		}
		cout << endl;
	}
}

bool look(vector<int> start, vector<vector<bool>> &cut) {
	bool db=(start[0]==0 && start[1]==7);

	setVal(1,start,cut);

	bool ok=0;
	int dis=1;
	vector<int> r,l,rEnd,lEnd;
	while (dis<min(N,M)) {
		r=add(start,{dis,dis}); l=add(start,{dis,-dis});
		if (!inBound(r) || !inBound(l) || !val(r) || !val(l) || isDone(r) || isDone(l)) {
			if (dis==1) return 0;
			break;
		}

		// r2/l2
		if (dis>1) {
			vector<int> r2=add(r,{0,-2}), l2=add(l,{0,2});
			// if (db) cout << v2s(r2) << " vs " << v2s(l2) << endl;
			if (val(r2) && val(l2) && !isDone(r2) && !isDone(l2)) {
				break;
			}
			// else if(db) {
			// 	cout <<"FAILED: " << v2s(r2) << " and " << v2s(l2) << endl;
			// 	cout << val(r2) << val(l2) << !isDone(r2) << !isDone(l2) << endl;
			// }
		}

		rEnd=r; lEnd=l;
		dis++;

		setVal(1,r,cut);
		setVal(1,l,cut);
	}

	dis=1;
	if (db) {
		// cout << v2s(rEnd) << " vs" << v2s(lEnd) << endl;
	}
	while (dis<min(N,M)) {
		r=add(rEnd,{dis,-dis}); l=add(lEnd,{dis,dis});
		if (!inBound(r) || !inBound(l) || !val(r) || !val(l) || isDone(r) || isDone(l)) {
			break;
		}
		
		// if (db) cout << v2s(r) << " " << v2s(l) << endl;
		
		setVal(1,r,cut);
		setVal(1,l,cut);

		if (r==l) {
			ok=1;
			break;
		}
		dis++;
	}
	return ok;
}

bool dfs(vector<int> start, vector<vector<bool>> vis) {
	stack<vector<int>> ST; ST.push(start); setVal(1,start,vis);
	setDone(1,start);
	while (!ST.empty()) {
		vector<int> top=ST.top(); ST.pop();
		
		for (vector<int> dir : dirs) {
			vector<int> pos=add(top,dir);
			if (!valAt(pos,vis)) {
				if (!val(pos)) {
					if (isDone(pos)) {
						// cout << "A" << endl;
						return 0;
					}
					ST.push(pos);
					setVal(1,pos,vis);
					setDone(1,pos);
				}
				else {
					// cout << "B: " << v2s(pos) << endl;
					return 0;
				}
			}
		}
	}
	return 1;

}

void solve() {
	vector<int> pos;
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			vector<vector<bool>> cut(N,vector<bool>(M));
			pos={y,x};
			if (isDone(pos)) continue;
			vector<int> below=add(pos,{1,0});
			if (val(pos) && !isDone(below)) {
				// cout << "trying: " << v2s(pos) << endl;
				if (look(pos,cut)) {
					// cout << "LOOKED!" << endl;
					// cout << v2s(pos) << " can work?..." << endl;
					// printV(cut);
					
					if (!val(below) && dfs(below,cut)) {
						// cout << v2s(pos) << " is good!" << endl;
						ANS++;
						// printDone();
					}
				}
			}
			
		}
	}
}

int main() {
	memset(DONE,0,sizeof(DONE));
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M;
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			char c; cin>>c;
			V[y][x]=(c=='#'?1:0);
		}
	}
	solve();
	cout << ANS << endl;
}