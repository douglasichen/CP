#include <bits/stdc++.h>
using namespace std;

int M;
vector<int> dp;

bool canSum(int sm, vector<int> nums) {
	if (dp[sm]!=0) return dp[sm]-1;

	if (sm==0) return 1;
	for (int i : nums) {
		int left=sm-i;
		if (left<0) continue;
		dp[left]=canSum(left,nums)+1;
		if (dp[left]==2) return 1;
	}
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M,N; cin>>M>>N;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];

	dp=vector<int>(M);
	cout << canSum(M,V) << endl;
	
}