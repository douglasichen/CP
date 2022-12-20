#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int MAXN=10;
int dp[MAXN+1][MAXN+1][MAXN+1][MAXN+1][MAXN+1]={0};
int psa[MAXN+1][MAXN+1]={0};
int N,a=1,b=1,c=1,ans=0,above=0;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	while (a)
		cin>>a>>b>>c,
		psa[a][b]=c;

	for (int y=1; y<=N; y++)
		for (int x=1; x<=N; x++)
			psa[y][x]+=psa[y][x-1];
	
	dp[1][1][1][1][1]=psa[1][1];

	for (int Y=1; Y<=N; Y++)
		for (int A1=1; A1<=N; A1++)
			for (int B1=1; B1<=N; B1++) {
				// best above A1,B1;
				above=0;
				for (int x=1; x<=A1; x++)
					for (int y=1; y<=B1; y++)
						above=max(above, dp[Y-1][x][A1][y][B1]);
				int left,right;
				for (int A2=A1; A2<=N; A2++)
					for (int B2=B1; B2<=N; B2++)
						left=max(A1,B1), right=min(A2,B2),
						dp[Y][A1][A2][B1][B2]=above + (psa[Y][A2]-psa[Y][A1-1])
						+ (psa[Y][B2]-psa[Y][B1-1])
						- (left<=right ? psa[Y][right]-psa[Y][left-1] : 0);
			}
	for (int A1=1; A1<=N; A1++)
		for (int B1=1; B1<=N; B1++)
			ans=max(ans, dp[N][A1][N][B1][N]);
	cout << ans << endl;


}