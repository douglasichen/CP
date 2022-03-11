#include <bits/stdc++.h>
using namespace std;

int N,K;
long long V[1000000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>K;
	for (int i=0; i<N; i++) {
		cin>>V[i];
	}
	long long ans=LLONG_MIN;
	for (int s=K; s<=N; s+=K) {
		long long sum=0;
		for (int i=0; i<s; i++) {
			sum+=V[i];
		}
		ans=max(sum,ans);
		int maxI=N-s;
		int right=s;
		for (int left=0; left<=maxI; left++) {
			sum-=V[left];
			sum+=V[right];
			ans=max(sum,ans);
		}
	}
	cout << max(ans,0LL) << endl;
 }