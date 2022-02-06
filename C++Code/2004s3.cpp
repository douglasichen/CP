#include <bits/stdc++.h>
using namespace std;

void solve() {

}

string inp[10][9];
bool know[10][9];
bool und[10][9];

bool isNum(string s) {
	char c=s[0];
	return !(c<'0' || c>'9');
}

vector<vector<int>> sep(vector<int> pos) {
	string s = inp[pos[0]][pos[1]];
	vector<vector<int>> seps;
	for (int i=0; i<s.size(); i+=3) {
		int y=s[i]-'A', x=s[i+1]-'0'-1;
		seps.push_back({y,x});
	}
	return seps;
}

// int it=0;
int findVal(vector<int> loc, bool met[10][9]) {
	// if (it>3) return -1;
	// it++;

	// ___
	met[loc[0]][loc[1]] = true;
	string locVal = inp[loc[0]][loc[1]];
	if (!isNum(locVal)) {
		vector<vector<int>> sepLocs = sep(loc);
		
		// cout << '('; 
		// for (vector<int> pos : sepLocs) cout << pos[0] << ',' << pos[1] << ' ';
		// cout << ')' << endl;
		
		int sum=0;
		bool ok=true;
		for (vector<int> sepLoc : sepLocs) {
			if (!met[sepLoc[0]][sepLoc[1]] && !und[sepLoc[0]][sepLoc[1]]) {
				int val = findVal(sepLoc, met);
				sum += val;
				// cout << "added val: " << val << endl;
			}
			else {
				// cout << "met=" << sepLoc[0] << ' ' << sepLoc[1] << endl;
				und[sepLoc[0]][sepLoc[1]]=true;
				met[sepLoc[0]][sepLoc[1]]=true;
				ok=false;
				break;
			}
		}
		// cout << "sum: " << sum << endl;
		if (ok) return sum;
	}
	else {
		return stoi(locVal);
	}
	return -1;
	
}


void print2d(bool arr[10][9]) {
	cout << "arr: " << endl;
	for (int y=0; y<10; y++) {
		for (int x=0; x<9; x++) {
			cout << arr[y][x] << ' ';
		}
		cout << endl;
	}
}

int main() {
	
	vector<vector<int>> unks;
	for (int y=0; y<10; y++) {
		for (int x=0; x<9; x++) {
			cin>>inp[y][x];
			if (isNum(inp[y][x])) know[y][x]=true;
			else unks.push_back({y,x});
		}
	}

	for (vector<int> unk : unks) {
		bool met[10][9];
		memset(met,0,sizeof met);
		// print2d(met);
		// cout << unk[0] << ',' << unk[1] << ": " << inp[unk[0]][unk[1]] << endl;
		int val = findVal(unk, met);
		inp[unk[0]][unk[1]] = to_string(val);
		
	}

	for (int y=0; y<10; y++) {
		for (int x=0; x<9; x++) {
			string val = inp[y][x];
			if (val=="-1") val="*";
			cout << val << ' ';
		}
		cout << endl;
	}

}