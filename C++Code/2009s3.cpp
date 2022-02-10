#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> g;
unordered_map<int, unordered_map<int,bool>> rem;

void add(int x, int y) {
	rem[x][y]=0;
	rem[y][x]=0;
	g[x].push_back(y);
	g[y].push_back(x);
}

void del(int x, int y) {
	rem[x][y]=1;
	rem[y][x]=1;
}

int countDeg(int start, int deg) {
	int ans=0;
	unordered_map<int,bool> vis; vis[start]=1;
	deque<vector<int>> dq; dq.push_back({start,0});
	
	while(!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();

		int x=back[0], dist=back[1];
		if (dist>deg) continue;
		if (dist==deg) {
			// cout << "getting to " << x << " takes "<< deg << endl; 
			ans++;
		}

		vector<int> friends=g[x];
		vector<int> validQ;
		for (int y : friends) {
			if (!rem[x][y]) {
				if (!vis[y])
					dq.push_front({y,dist+1});

				validQ.push_back(y);
				vis[y]=1;
			}
		}
		g[x]=validQ;
	}
	return ans;
}

int dist(int start, int goal) {
	unordered_map<int,bool> vis; vis[start]=1;
	deque<vector<int>> dq; dq.push_back({start,0});
	
	while(!dq.empty()) {
		vector<int> back=dq.back(); dq.pop_back();

		int x=back[0], dist=back[1];
		if (x==goal) return dist;

		vector<int> friends=g[x];
		vector<int> validQ;
		for (int y : friends) {
			if (!rem[x][y]) {
				if (!vis[y])
					dq.push_front({y,dist+1});

				validQ.push_back(y);
				vis[y]=1;
			}
		}
		g[x]=validQ;
	}
	return -1;
}

int main() {
	add(2,6);
	add(6,1);
	add(6,3);
	add(6,4);
	add(6,5);
	add(6,7);
	add(6,7);
	add(3,4);
	add(3,5);
	add(3,15);
	add(4,5);
	add(7,8);
	add(8,9);
	add(9,12);
	add(9,10);
	add(10,11);
	add(11,12);
	add(12,13);
	add(13,14);
	add(13,15);
	add(16,17);
	add(17,18);
	add(16,18);




	vector<int> queries;
	char com='i';
	while (com!='q') {
		cin>>com;
		if (com=='q') break;

		int x,y;
		switch(com) {
			case 'i':
			cin>>x>>y;
			add(x,y);
			break;
			case 'd':
			cin>>x>>y;
			del(x,y);
			break;
			case 'n':
			cin>>x;
			queries.push_back(countDeg(x,1));
			break;
			case 'f':
			cin>>x;
			queries.push_back(countDeg(x,2));
			break;
			case 's':
			cin>>x>>y;
			queries.push_back(dist(x,y));
			break;
		}
	}
	for (int q : queries) {
		if (q==-1) {
			cout << "Not connected" << endl;
		}
		else {
			cout << q << endl;
		}
	}
}