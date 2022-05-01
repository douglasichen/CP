#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	

	int N,K; cin>>N>>K;
	vector<int> V(N);
	vector<bool> have(1e6);
	for (int i=0; i<N; i++) cin>>V[i],have[V[i]]=1;
	
	
	for (int i=2; i<=1e6; i++) {
		int a=i,cnt=0;
		while (a<=1e6) {
			cnt++;
			if (have[a]) {
				
			}
			a+=i;
		}
	}

}