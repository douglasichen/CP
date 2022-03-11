#include <bits/stdc++.h>
using namespace std;

int X,N;
vector<vector<int>> V;

bool sorter(int &a, int &b) {
	return V[a][1]>V[b][1];
}

bool sorter2(vector<int> a, vector<int> b) {
	return a[0]<b[0];
}

void ppq(priority_queue<int,vector<int>,decltype(&sorter)> pq) {
	if (pq.empty()) return;
	while (!pq.empty()) {
		cout << pq.top() << ' '; pq.pop();
	}
	cout << endl;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int mxF=0;
	cin>>X>>N;
	V=vector<vector<int>>(N,vector<int>(2));
	for (int i=0; i<N; i++) {
		cin>>V[i][0]>>V[i][1];
		mxF=max(mxF,V[i][1]);
	}
	sort(V.begin(),V.end(),sorter2);

	// for (vector<int> v : V) cout << v[0] << ' ' << v[1] << ", ";
	// cout << endl;

	int time=0, ans=0;
	vector<bool> done(N);
	priority_queue<int,vector<int>,decltype(&sorter)> cool(sorter);

	int end=0;
	while (time<=mxF) {
		for (int i=end; i<N; i++) {
			if (V[i][0]-time>X) {
				end=i;
				break;
			}
			end=i+1;
			
			cool.push(i);
		}

		while (!cool.empty()) {
			int top=cool.top(); cool.pop();
			if (time<=V[top][1]) {
				ans++;
				break;
			}
		}
		time++;
	}
	cout << ans << endl;
}