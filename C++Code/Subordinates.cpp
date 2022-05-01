#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> dp;
vector<vector<int>> T;

int trav(int at) {
	if (T[at].size()==0) return 0;
	if (dp[at]!=-1) return dp[at];
	int sm=0;
	for (int i : T[at]) {
		sm+=trav(i)+1;
	}
	dp[at]=sm;
	return dp[at];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	dp=vector<int>(N+1,-1);
	T=vector<vector<int>>(N+1);
	for (int i=2,boss; i<=N; i++) {
		cin>>boss;
		T[boss].push_back(i);
	}
	trav(1);
	for (int i=1; i<=N; i++) {
		cout << (dp[i]!=-1 ? dp[i] : 0) << ' ';
	}
	cout << endl;
}