#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	long long sm=0;
	vector<int> ans(N);
	for (int i=1; i<=N; i++) sm+=i,ans[i-1]=i;
	long long d=sm/K;
	if (d*K<sm) d++;
	sm-=N;
	long long need=d*K-sm;
	ans.back()=need;
	cout << ans.front();
	for (int i=1; i<N; i++) cout << ' ' << ans[i];
	cout << '\n';
}