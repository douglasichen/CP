#include <bits/stdc++.h>
using namespace std;

int N,M,md=1e9+7;
vector<long long> V;

vector<vector<long long>> dp(301,vector<long long>(1e5+1,-1));
vector<vector<long long>> dp2(101,vector<long long>(1e5+1,-1)); // from -> dis (special case free end)


long long solve(int l, int r, int from, int goal) {
	// if the goal's location is reached than that is a valid path
	if (l==r+1) {
		if (goal==-1) return 1;
		return abs(from-goal)<=1;
	}
	int x=r-l+1;
	long long ways=0;

	// edge case
	if (from==-1 || goal==-1) {
		if (from==-1) {
			for (int i=1; i<=M; i++) {
				ways+=solve(l+1,r,i,goal);
			}
			return ways%md;
		}
		else {
			if (dp2[from][l]!=-1) return dp2[from][l];
			
			int mn=from-1, mx=from+1;
			mn=max(mn,1);
			mx=min(mx,M);
			for (int i=mn; i<=mx; i++) {
				ways+=solve(l+1,r,i,-1);
			}
			dp2[from][l]=ways%md;
			return dp2[from][l];
		}
	}
	else {
		int y=abs(from-goal);
		
		// using delta x and delta y, dp it
		if (dp[from+goal][x]!=-1) return dp[from+goal][x];
		
		// what to rec
		// int mn=goal-x, mx=goal+x;
		// mn=max(mn,from-1);
		// mx=min(mx,from+1);
		int mn=from-1,mx=from+1;;
		mn=max(mn,1);
		mx=min(mx,M);
		
		for (int i=mn; i<=mx; i++) {
			ways+=solve(l+1,r,i,goal);
		}
		dp[from+goal][x]=ways%md;
		return dp[from+goal][x];
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	V=vector<long long>(N);
	vector<long long> ways;
	for (int i=0; i<N; i++) cin>>V[i];
	
	long long ans=1;
	int start=0;
	for (int i=0; i<N; i++) {
		int end=i-1,from=-1,goal=V[i];
		if (start>0) from=V[start-1];
		
		if (V[i]!=0) {
			// int x=i-start+1,y=abs(goal-from);
			// if (x+1<y) {
			// 	ans=0;
			// 	break;
			// }

			if (i>0 && V[i-1]==0) ways.push_back(solve(start,end,from,goal));
			start=i+1;
			
		}
		else if (i==N-1) {
			ways.push_back(solve(start,i,from,-1));
 		}
	}
	// for (int i : ways) cout << i << ' ';
	// cout << endl;
	
	for (int i=0; i<N; i++) {
		if (V[i]>M) {
			ans=0;
			break;
		}
		if (i>0 && V[i]!=0 && V[i-1]!=0) {
			if (abs(V[i]-V[i-1])>1) {
				ans=0;
				break;
			}
		}
	}

	for (long long i : ways) {
		ans*=i;
		ans%=md;
	}
	cout << ans << endl;
}