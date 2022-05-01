#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<long long> ans(100001);
	
	ans[2]=6;
	ans[3]=28;
	ans[4]=96;
	long long bad=0;
	for (long long k=5; k<=N; k++) {
		long long options=k*k-1, all=(options*options+options)/2;
		bad+=(20+4*(2*k-9));
		ans[k]=all-bad;
	}
	for (int i=1; i<=N; i++) cout << ans[i] << endl;
}