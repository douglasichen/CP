#include <bits/stdc++.h>
using namespace std;

int md=1e9+7;

int solve(int a, int b) {
	vector<long long> E={a};
	for (int i=1; (1<<i)<=b; i++) {
		E.push_back(E.back()*E.back());
		E.back()%=md;
	}

	long long ans=1;
	int i=0;
	while (b) {
		cout << i << ' ';
		if (b&1) {
			ans*=E[i];
			ans%=md;
		}
		b>>=1;
		i++;
	}
	cout << endl;
	return ans;

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	int ans[T];
	for (int i=0; i<T; i++) {
		int a,b; cin>>a>>b;
		ans[i]=solve(a,b);
	}	
	for (int i : ans) cout << i << endl;
}