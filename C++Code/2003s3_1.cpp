#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> g;
vector<vector<bool>> vis;
int f,r,c;

vector<vector<int>> dirs = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1},
};

vector<int> add(vector<int> a, vector<int> b) {
	return {a[0]+b[0], a[1]+b[1]};
}

bool good(vector<int> pos) {	
	if (pos[0]<0 || pos[0]>=r || pos[1]<0 || pos[1]>=c)
		return 0;

	if (g[pos[0]][pos[1]]=='I')	
		return 0;

	if (vis[pos[0]][pos[1]])
		return 0;
	
	return 1;
}

int calcSize(vector<int> start) {	
	int ans=1;
	stack<vector<int>> s;
	s.push(start);
	vis[start[0]][start[1]]=1;

	while (!s.empty()) {
		vector<int> t=s.top(); s.pop();
		
		for (vector<int> dir : dirs) {
			vector<int> nPos=add(t,dir);
			if (good(nPos)) {
				s.push(nPos);
				ans++;
				vis[nPos[0]][nPos[1]]=1;
			}
		}
	}
	return ans;
}

int main() {
	cin>>f>>r>>c;
	g=*(new vector<vector<char>>(r,*(new vector<char>(c))));
	vis=*(new vector<vector<bool>>(r,*(new vector<bool>(c))));

	vector<vector<int>> emps;
	for (int y=0; y<r; y++) {
		for (int x=0; x<c; x++) {
			cin>>g[y][x];
			if (g[y][x]=='.')
				emps.push_back({y,x});
		}
	}

	vector<int> roomSizes;
	for (vector<int> emp : emps) {
		if (!vis[emp[0]][emp[1]]) {
			roomSizes.push_back(calcSize(emp));
		}
	}
	sort(roomSizes.begin(), roomSizes.end(), greater<int>());


	int filled=0;
	for (int rs : roomSizes) {
		if (f-rs<0) break;
		filled++;
		f-=rs;
	}
	cout << filled <<  " room" << (filled!=1 ? "s" : "") << ", " << f << " square metre(s) left over" << endl;
}