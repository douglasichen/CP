#include <bits/stdc++.h>
using namespace std;

long long solve(int n, vector<long long> roads) {
	if (n==1) return 0;

	sort(roads.begin(), roads.end());

	long long ans=0;
	for (int i=1; i<n; i++) {
		ans+=(roads[i]+roads[0]);
	}
	return ans;

	// deque<int> dq;
	// dq.push_back(roads[0]);
	// dq.push_back(roads[1]);
	// dq.push_front(roads[2]);
	// for (int i=3; i<n; i++) {
	// 	int right=dq.back(), left=dq.front();
	// 	if (left<right) {
	// 		dq.push_front(roads[i]);
	// 	}
	// 	else {
	// 		dq.push_back(roads[i]);
	// 	}
	// }
	// long long ans=0;
	// while(dq.size()>1) {
	// 	int a=dq.back();
	// 	dq.pop_back();
	// 	int b=dq.back();
	// 	ans+=a+b;
	// }
	// return ans;
}

int main() {
	int n; cin>>n;
	vector<long long> roads(n);
	for (int i=0; i<n; i++) {
		cin>>roads[i];
	}
	cout << solve(n,roads) << endl;
}