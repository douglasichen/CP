#include <bits/stdc++.h>
using namespace std;

int n,m,k,q;
vector<vector<pair<int,int>>> routes;

long long solve(int c, int d) {
	if (c==d) return 0;

	vector<int> vis(n+1);
	deque<vector<long long>> dq;
	dq.push_back({(long long)c,0LL,0LL});		// c
	vis[c]=true;

	long long bestT=-1LL;

	while(!dq.empty()) {
		vector<long long> back=dq.back();
		dq.pop_back();

		if (back[2]==k) continue;

		vector<pair<int,int>> connected = routes[back[0]];
		for (pair<int,int> connect : connected) {
			if (connect.first!=d) {
				if (!vis[connect.first]) {
					dq.push_front({(long long)connect.first, back[1]+(long long)connect.second, back[2]+1LL});
				}
				vis[connect.first]=true;
			}
			else {
				long long myT=back[1]+(long long)connect.second;
				long long myK=back[2]+1LL;

				if (myK<=k) {
					if (bestT==-1LL) bestT=myT;
					else bestT=min(bestT,myT);
				}
			}
		}
	}
	return bestT;
	// return -1;
}

long long solve2(int c, int d) {
	if (c==d) return 0;

	stack<pair<vector<long long>, unordered_map<int,bool>>> s;	// data (node #, t dis, k dis) , inPath
	vector<long long> fData = {c, 0, 0};

	unordered_map<int,bool> firstInPath;
	firstInPath[c]=true;
	
	s.push({fData,firstInPath});

	long long bestT=-1LL;

	while (!s.empty()) {
		pair<vector<long long>, unordered_map<int,bool>> top = s.top();
		s.pop();

		vector<long long> data = top.first;
		unordered_map<int,bool> inPath = top.second;

		if (data[2]<=k) {
			if (data[0]==(long long)d) {
				if (bestT==-1LL) bestT=data[1];
				else bestT=min(bestT, data[1]);
				continue;
			}
		}
		else continue;
		
		vector<pair<int,int>> connected = routes[(int)data[0]];
		for (pair<int,int> connection : connected) {
			if (!inPath[connection.first]) {
				unordered_map<int,bool> newInPath = inPath;
				newInPath[connection.first]=true;
				
				long long newT = data[1] + (long long)connection.second;
				long long newK = data[2] + 1LL;
				vector<long long> newData = {(long long)connection.first, newT, newK};
				s.push({newData, newInPath});
			}
		}
	}
	
	return bestT;
}

int main() {
	cin>>n>>m;
	routes = *(new vector<vector<pair<int,int>>>(n+1));
	for (int i=0; i<m; i++) {
		int a,b,t; cin>>a>>b>>t;
		routes[a].push_back({b,t});
	}
	
	cin>>k>>q;
	vector<long long> ans(q);
	for (int i=0; i<q; i++) {
		int c,d; cin>>c>>d;
		ans[i]=solve2(c,d);
	}
	for (long long i : ans) cout << i << endl;
}