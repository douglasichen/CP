#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	sort(V.begin(), V.end());
	long long a=0;
	for (int i=0; i<N-1; i++) {
		int left=M-V[i];
		if (left>=0) {
			int L=i+1, R=N-1;
			while (L<R) {
				int mid=L+R+1>>1;
				if (V[mid]<=left) L=mid;
				else R=mid-1;
			}
			if (V[L]<=left) a+=L-i;
		}
	}
	int md=1e9+7;
	cout << a%(md) << '\n';
	
}