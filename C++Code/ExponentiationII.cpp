#include <bits/stdc++.h>
using namespace std;

int md=1e9+7;

int solve(long long a, long long b) {
	vector<long long> E={a};
	for (int i=1; (1<<i)<=b; i++) {
		E.push_back(E.back()*E.back());
		E.back()%=md;
	}

	long long ans=1;
	int i=0;
	while (b) {
		if (b&1) {
			ans*=E[i];
			ans%=md;
		}
		b>>=1;
		i++;
	}
	return ans;

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	int ans[T];
	for (int i=0; i<T; i++) {
		long long a,b,c; cin>>a>>b>>c;
		ans[i]=solve(a,solve(b,c));
	}	
	for (int i : ans) cout << i << endl;
}