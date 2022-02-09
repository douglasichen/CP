#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> a) {
	sort(a.begin(), a.end());
	vector<int> odd, even;
	for (int i : a) {
		if (i%2==0) even.push_back(i);
		else odd.push_back(i);
	}
	return even.size()/2 + odd.size()/2;
}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for (int i=0; i<n; i++)
		cin>>a[i];
	cout << solve(n,a) << endl;
}