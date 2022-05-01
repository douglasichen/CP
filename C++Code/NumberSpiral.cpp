#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<long long> ans(N);
	for (int i=0; i<N; i++) {
		long long y,x; cin>>y>>x;
		if (y>x) {
			long long start;
			if (y%2==0) {
				start=y*y;
				ans[i]=start-x+1;
			}
			else {
				start=(y-1)*(y-1); start++;
				ans[i]=start+x-1;
			}
		}
		else {
			long long start;
			if (x%2==0) {
				start=(x-1)*(x-1); start++;
				ans[i]=start+y-1;
			}
			else {
				start=x*x;
				ans[i]=start-y+1;
			}
		}
	}
	for (long long i : ans) cout << i << endl;
}