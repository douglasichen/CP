#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("diamond.in","r",stdin); 
	freopen("diamond.out","w",stdout); 

	int N,K; cin>>N>>K;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	sort(V.begin(),V.end(),greater<int>());

	vector<int> bestStart(N),bestEnd(N);
	for (int a=0,b=0; b<N; b++) {
		while (a<N-1 && V[a]-V[b]>K) a++;
		bestEnd[b]=b-a+1;
	}
	for (int a=0,b=0; a<N; a++) {
		b=max(b,a);
		while (b<N-1 && V[a]-V[b+1]<=K) b++;
		bestStart[a]=b-a+1;
	}
	vector<int> mxStarts(N+1);
	mxStarts[N-1]=bestStart[N-1];
	for (int i=N-2; i>=0; i--) {
		mxStarts[i]=max(mxStarts[i+1],bestStart[i]);
	}
	int ans=0;
	for (int i=0; i<N; i++) {
		ans=max(ans,bestEnd[i]+mxStarts[i+1]);
	}
	ans=max(ans,bestStart[0]);
	cout << ans << endl;
}