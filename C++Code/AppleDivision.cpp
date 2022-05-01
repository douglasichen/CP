#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;

	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	if (N==1) {
		cout << V[0] << endl;
		return 0;
	}

	long long sm=0;
	for (int i : V) sm+=i;

	long long a=0,b=0,target=sm/2;
	vector<bool> taken(N);
	for (int i=0; i<N; i++) {
		long long curDif=abs(a-target);
		pair<long long,int> best={curDif,-1}; // dif,i
		for (int i=0; i<N; i++) {
			if (taken[i]) continue;
			long long nDif=abs(a+V[i]-target);
			if (nDif<best.first) {
				best={nDif,i};
			}
		}
		if (best.second==-1) break;
		else {
			a+=V[best.second];
			taken[best.second]=1;
		}
	}
	for (int i=0; i<N; i++) {
		if (!taken[i]) {
			b+=V[i];
		}
	}
	cout << abs(a-b) << endl;
}