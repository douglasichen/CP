#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

vector<vector<char>> room;
vector<vector<int>> impGoalRoom;
vector<pi> goals;
vi distances;
vector<pi> cams;
pi gPos;

vector<pi> gDirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int n,m;

void printRoom(vector<vector<char>> myRoom) {
	for (int y=0; y<n; y++) {
		for (int x=0; x<m; x++) {
			cout<<myRoom[y][x]<<' ';
		}
		cout<<endl;
	}
}

void solve() {

}

pi dirConv(char c) {
	if (c=='U') return {-1,0};
	if (c=='D') return {1,0};
	if (c=='R') return {0,1};
	if (c=='L') return {0,-1};
	return {0,0};
}

bool posAtChar(pi pos, char c, vector<vector<char>> newRoom) {
	return newRoom[pos.F][pos.S] == c;
}

pi piAdd(pi pi1, pi pi2) {
	return {pi1.F+pi2.F, pi1.S+pi2.S};
}

void printPi(pi p) {
	cout<<p.F<<' '<<p.S<<endl;
}
// int c=0;

void changeDis(pi pos, int dist) {
	cout<<pos.F<<' '<<pos.S<<": "<<dist;
	for (int i=0; i<goals.size(); i++) {
		if (goals[i]==pos) {
			distances[i] = dist;
			break;
		}
	} 
}

int c=0;
void findDistances(pi startPos, vector<vector<char>> newRoom, int distanceFromStart) {
	if (posAtChar(startPos, '.', newRoom)) {
		changeDis(startPos, distanceFromStart);
		return;
	}
	newRoom[startPos.F][startPos.S] = 'W';
	for (int i=0; i<gDirs.size(); i++) {
		pi dir = gDirs[i];
		pi nextPos = piAdd(startPos, dir);
		
		if (!posAtChar(nextPos,'W', newRoom)) {
			if (c<10) {
				cout<<"nextPos: ";
				printPi(nextPos);
				printRoom(newRoom);
				c++;
			}
			findDistances(nextPos, newRoom, distanceFromStart+1);
		}
	}
}


int main() {
	cin>>n>>m;
	room = *(new vector<vector<char>>(n,*(new vector<char>(m))));
	impGoalRoom = *(new vector<vi>(n, *(new vi(m))));
	for (int y=0; y<n; y++) {
		for (int x=0; x<m; x++) {
			char inp; cin>>inp;
			room[y][x]=inp;
			if (inp=='S') gPos = {y,x};
			if (inp=='C') cams.PB({y,x});
			if (inp=='.') goals.PB({y,x});
		}
	}
	distances = *(new vi(goals.size(),-1));
	for (int i=0; i<cams.size(); i++) {
		pi cam = cams[i];
		for (int o=0; o<gDirs.size(); o++) {
			pi dir = gDirs[o];
			pi ray = cam;
			while (!posAtChar(ray,'W', room)) {
				ray = piAdd(ray, dir);
				if (posAtChar(ray,'.', room)) {
					impGoalRoom[ray.F][ray.S] = 1;
					room[ray.F][ray.S] = 'W';
					break;
				}
			}
		}
		room[cam.F][cam.S] = 'W';
	}
	cout<<"goals: ";
	for (int i=0; i<goals.size(); i++) {
		cout<<goals[i].F<<' '<<goals[i].S<<", ";
	}
	cout<<endl;
	
	printRoom(room);
	
	cout<<"distances: "<<endl;
	for (int i=0; i<distances.size(); i++) {
		cout << distances[i] << endl;
	}
	cout<<"gPos: ";
	printPi(gPos);
	findDistances(gPos, room, 0);
	
	cout<<"distances: "<<endl;
	for (int i=0; i<distances.size(); i++) {
		cout << distances[i] << endl;
	}
	// solve();
}