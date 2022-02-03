#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

vector<vi> chart(3,*(new vector<int>(3)));
vector<vi> unk(3,*(new vector<int>(3)));
vector<vi> noUnk(3,*(new vector<int>(3)));

bool brk=false;

void printChart(vector<vi> c) {
	for (int y=0; y<3; y++) {
		for (int x=0; x<3; x++) {
			cout<<c[y][x]<<' ';
		}
		cout<<endl;
	}
}
int c=0;
bool checkPairs() {
	bool none=false;
	for (int i=0; i<2&&none==false; i++) {
		none=true;
		for (int y=0; y<3; y++) {
			int rowUnk = 0;
			int unkIndex = 0;
			for (int x=0; x<3; x++) {
				if (unk[y][x]) {
					rowUnk++;
					unkIndex=x;
				}
			}
			if (rowUnk==1) {
				if (unkIndex==1) {
					int sum = chart[y][0]+chart[y][2];
					if (sum%2!=0) {
						return false;
					}
					chart[y][1]=sum/2;
				}
				else if (unkIndex==0) {
					chart[y][0]=chart[y][1]*2-chart[y][2];
				}
				else {
					chart[y][2]=chart[y][1]+(chart[y][1]-chart[y][0]);
				}
				unk[y][unkIndex] = 0;
			}
		}
		for (int x=0; x<3; x++) {
			int colUnk = 0;
			int unkIndex = 0;
			for (int y=0; y<3; y++) {
				if (unk[y][x]) {
					colUnk++;
					unkIndex=y;
				}
			}
			if (colUnk==1) {
				if (unkIndex==1) {
					
					int sum = chart[0][x]+chart[2][x];
					if (sum%2!=0) {
						return false;
					}
					chart[1][x]=sum/2;
				}
				else if (unkIndex==0) {
					chart[0][x]=chart[1][x]*2-chart[2][x];
				}
				else {
					chart[2][x]=chart[1][x]+(chart[1][x]-chart[0][x]);
				}
				unk[unkIndex][x] = 0;
				none=false;
			}
		}
	}
	for (int y=0; y<3; y++) {
		if (chart[y][2]!=chart[y][1]*2-chart[y][0]) {
			return false;
		}
		int sum = chart[y][0]+chart[y][2];
		if (sum%2!=0) {
			return false;
		}
	}
	for (int x=0; x<3; x++) {
		if (chart[2][x]!=chart[1][x]*2-chart[0][x]) {
			return false;
		}
		int sum = chart[0][x]+chart[2][x];
		if (sum%2!=0) {
			return false;
		}
	}
	
	return true;
}

void addToChart(int j) {
	vector<pi> dirs = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
	for (int i=0; i<dirs.size(); i++) {
		if (unk[1][1]!=unk[1+dirs[i].F][1+dirs[i].S]) {
			if (i<=3) {
				if (unk[1][1]==0) {
					chart[1+dirs[i].F][1+dirs[i].S] = chart[1][1]+j;
					unk[1+dirs[i].F][1+dirs[i].S] = 0;
				}
				else {
					chart[1][1] = chart[1+dirs[i].F][1+dirs[i].S]+j;
					unk[1][1] = 0;
				}
				return;
			}
			else {
				if (unk[1][1]==1) {
					chart[1][1+dirs[i].S]  = chart[1+dirs[i].F][1+dirs[i].S]+j;
					unk[1][1+dirs[i].S] = 0;
				}
				else {
					chart[1+dirs[i].F][1+dirs[i].S] = chart[1][1+dirs[i].S]+j;
					unk[1+dirs[i].F][1+dirs[i].S] = 0;
				}
				return;
			}
		}
	}
}


void addToChart2(vector<vi> pastChart, vector<vi> pastUnk) {
	for (int o=0; o<100; o++) {
		for (int i=-1; i<=1; i+=2) {
			int j = o*i;
			addToChart(j);
			if (!checkPairs()) {
				if (unk!=noUnk) {
					continue;
				}
				chart = pastChart;
				unk = pastUnk;
			}
			else {
				brk=true;
				return;
			}
			if (brk) return;
			if (j==0) break;
		}
	}
}

int main() {
	for (int y=0; y<3; y++) {
		for (int x=0; x<3; x++) {
			string inp; cin>>inp;
			if (inp=="X") unk[y][x]=1;
			else chart[y][x]=stoi(inp); 
		}
	}
	vector<vi> pastChart = chart;
	vector<vi> pastUnk = unk;
	
	
	if (!checkPairs()) {
		for (int o=0; o<100; o++) {
			for (int i=-1; i<=1; i+=2) {
				int j = o*i;
				addToChart(j);
				if (!checkPairs()) {
					
					if (unk!=noUnk) {
						addToChart2(chart,unk);
					}
					else {
						chart = pastChart;	
						unk = pastUnk;
					}
				}
				else brk=true;
				if (o==0) break;
			}
			if (brk) break;
		}
	}
	printChart(chart);
}