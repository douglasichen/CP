#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef vector<vector<int>> vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(x,n) for(int x = 0; x < n; ++x)

#define printV(v) FOR(x,v.size()) cout<<v[x]<<' '; cout<<endl;

vector<vector<string>> grid(3,*(new vector<string>((3))));

void solve() {

}

void solvePos() {
	int progress=1;
	while (progress) {
		progress=0;
		FOR(o,3) {
			vector<string> row = grid[o];
			int xCount=0;
			for (string s : row) xCount+=(s=="X");
			if (xCount==1) {
				FOR(i,3) {
					string s = row[i];
					if (s=="X") {
						switch(i) {
							case 0:
							grid[o][0]=to_string(stoi(grid[o][1]) - (stoi(grid[o][2]) - stoi(grid[o][1])));
							break;
							
							case 1:
							grid[o][1]=to_string((stoi(grid[o][0])+stoi(grid[o][2]))/2);
							break;
							
							case 2:
							grid[o][2]=to_string(stoi(grid[o][1]) + (stoi(grid[o][1])-stoi(grid[o][0])));
							break;
						}
						break;
					}
				}
				progress++;
			}
		}
		FOR(x,3) {
			vector<string> col;
			int xCount=0;
			FOR(y,3) {
				col.PB(grid[y][x]);
				if (grid[y][x]=="X") xCount++;
			}
			if (xCount==1) {
				FOR(y,3) {
					string s = col[y];
					if (s=="X") {
						switch (y) {
							case 0:
							grid[0][x] = to_string()
							break;

							case 1:
							break;

							case 2:
							break;
						}
					}
				}
				progress++;
			}
		}
	}
}

int main() {
	FOR(y,3) {
		FOR(x,3) {
			cin>>grid[y][x];
		}
	}

	solvePos();
}