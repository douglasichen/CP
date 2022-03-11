#include <bits/stdc++.h>
using namespace std;

int N,T,K,V;
int ans=0,has=0;
vector<bool> B;
void iter(int start) {
	int need=K-has;
	for (int i=start; need; i--) {
		if (!B[i]) {
			B[i]=1;
			has++;
			need--;
			ans++;
		}
	}
}
 
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>T>>K>>V;
	B=vector<bool>(N);
	for (int i=0; i<V; i++) {
		int ind; cin>>ind;
		B[ind-1]=1;
	}

	for (int i=0; i<T; i++) has+=B[i];
	if (has<K) iter(T-1);
	
	int bnd=N-T;
	for (int left=0; left<bnd; left++) {	// left is getting rid
		int right=left+T;
		has-=B[left];
		has+=B[right];
		
		if (has<K) iter(right);
	}

	cout << ans << endl;
}