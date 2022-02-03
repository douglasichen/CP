#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

vector<pi> dirs = {
	{1,0},{-1,0},{0,1},{0,-1}
};

int f, w, l;
vector<vector<char>> plan;

pi findEmpty() {
	for (int y=0; y<l; y++) {
		for (int x=0; x<w; x++) {
			if (plan[y][x]=='.') return {x,y};
		}
	}
	return {-1,-1};
}

pi addPi(pi a, pi b) {
	return {a.F + b.F, a.S + b.S};
}

int spread(pi pos) {
	if (pos.S<0 || pos.S>l-1 || pos.F<0 || pos.F>w-1) return 0;
	if (plan[pos.S][pos.F] == 'I') return 0;
	
	plan[pos.S][pos.F] = 'I';
	int area = 1;
	
	for (int i=0; i<4; i++) {
		area += spread(addPi(pos,dirs[i]));
	}
	return area;
}


void printPlan() {
	for (int y=0; y<l; y++) {
		for (int x=0; x<w; x++) {
			cout<<plan[y][x];
		}
		cout<<endl;
	}
	cout<<endl;
}

void printPi(pi a) {
	cout<<a.F<<" "<<a.S<<endl;
}

int main() {
	cin>>f>>l>>w;
	plan = *(new vector<vector<char>>(l, *(new vector<char>(w))));
	for (int y=0; y<l; y++) {
		for (int x=0; x<w; x++) {
			cin>>plan[y][x];
		}
	}
	// printPlan();
	vi roomSizes;

	pi emp = {0,0};
	while (emp.F!=-1) {
		emp = findEmpty();
		if (emp.F==-1) break;
		// printPi(emp);
		int roomArea = spread(emp);
		roomSizes.PB(roomArea);
		// cout<<roomArea<<endl;
	}
	sort(roomSizes.begin(), roomSizes.end(), greater<int>());

	int roomCount = 0;
	int leftOver = 0;
	for (int i=0; i<roomSizes.size(); i++) {
		if (f-roomSizes[i]>=0) {
			roomCount++;
			f-=roomSizes[i];
		}
		else break;
	}
	leftOver = f;
	string str = "s";
	if (roomCount==1) str = "";
	cout<<roomCount<<" room"<<str<<", "<<leftOver<<" square metre(s) left over"<<endl;
}

