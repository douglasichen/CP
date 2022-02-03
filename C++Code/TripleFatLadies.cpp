#include <bits/stdc++.h>
using namespace std;

bool valid(long long k) {
	k = pow(k,3);
	string s=to_string(k);

	if ((int)s.size()<3) return false;
	string p=s.substr(s.size()-3, 3);
	return p=="888";
}

long long solve(long long n) {
	long long ans=192LL;
	while (ans<=n) {
		ans+=250LL;
	}
	return ans;
}

int main() {

	// for (long long i=1; i<1000; i++) {
	// 	if (valid(i)) {
	// 		cout << i << ' ';
	// 	}
	// }
	// cout << endl;

	int t; cin>>t;
	vector<long long> ans;
	for (int i=0; i<t; i++) {
		long long n; cin>>n;
		ans.push_back(solve(n+1));
	}
	for (int i=0; i<ans.size(); i++) {
		cout <<ans[i] << endl;
	}

}