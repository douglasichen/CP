#include <bits/stdc++.h>
using namespace std;

int r,c,m;
vector<vector<char>> g;
vector<char> go;
vector<vector<int>> emps;


vector<vector<int>> dirs = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0},
};

vector<int> add(vector<int> a, vector<int> b) {
	return {a[0]+b[0], a[1]+b[1]};
}

vector<vector<vector<int>>> matrix;

bool good(vector<int> pos) {
	if (pos[0]<0 || pos[0]>=r || pos[1]<0 || pos[1]>=c)
		return 0;

	if (g[pos[0]][pos[1]]=='X')
		return 0;
	
	return 1;
}

void update(vector<int> offset) {
	for (vector<vector<int>> series : matrix) {
		bool ok=1;
		for (vector<int> pos : series) {
			vector<int> loc=add(pos,offset);
			if (!good(loc)) {
				ok=0;
				break;
			}
		}
		if (ok) {
			vector<int> end=add(series.back(),offset);
			g[end[0]][end[1]]='*';
		}
	}
}

int main() {
	cin>>r>>c;
	g=*(new vector<vector<char>>(r, *(new vector<char>(c))));
	for (int y=0; y<r; y++) {
		for (int x=0; x<c; x++) {
			cin>>g[y][x];
			if (g[y][x]=='.')
				emps.push_back({y,x});
		}
	}

	cin>>m;
	// go=*(new vector<char>(m));
	vector<char> inps(m);
	int rCount=0, lCount=0;
	for (int i=0; i<m; i++) {
		cin>>inps[i];
		if (inps[i]=='R') rCount++;
		else if (inps[i]=='L') lCount++;
		else {
			// add l and r
			int rem=min(rCount,lCount);
			rCount-=rem;
			lCount-=rem;
			for (int i=0; i<rCount; i++) go.push_back('R');
			for (int i=0; i<lCount; i++) go.push_back('L');

			// reset
			go.push_back('F');
			rCount=0;
			lCount=0;
		}
	}




	// rotation matrix
	int dirInd=0;
	vector<vector<int>> rightMat;
	vector<int> pos={0,0};
	rightMat.push_back(pos);
	for (char instruct : go) {
		if (instruct=='F') {
			vector<int> dir=dirs[dirInd];
			pos=add(pos,dir);
			rightMat.push_back(pos);
		}
		else {
			int rot=(instruct=='R' ? 1 : -1);
			dirInd+=rot;
			
			// loop
			if (dirInd<0) dirInd=3;
			else if (dirInd>=4) dirInd=0;
		}
	}
	
	// other rots
	vector<vector<int>> upMat(rightMat.size()), leftMat(rightMat.size()), downMat(rightMat.size());
	for (int i=0; i<rightMat.size(); i++) {
		int a=rightMat[i][0], b=rightMat[i][1];
		upMat[i]={b,-a};
		leftMat[i]={-a,-b};
		downMat[i]={-b,a};
	}
	
	matrix={rightMat,upMat,leftMat,downMat};


	for (vector<int> emp : emps) {
		update(emp);
	}

	for (int y=0; y<r; y++) {
		for (int x=0 ;x<c; x++) {
			cout << g[y][x];
		}
		cout << endl;
	}
}