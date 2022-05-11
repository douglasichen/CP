#include <bits/stdc++.h>
using namespace std;

vector<long long> facs(2e6,1);
long long md=1e9+7;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i=2; i<2e6; i++) facs[i]=i*facs[i-1]%md;
	long long W,H,X; cin>>W>>H>>X;
	long long ans=
	cout << ans << endl;
}