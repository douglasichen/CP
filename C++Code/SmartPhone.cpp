#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int n; cin>>n;
	vector<int> v(n);
	for (int i=0; i<n; i++)
		cin>>v[i];
	sort(v.begin(), v.end());

	long long mx=0;
	for (int i=0; i<n; i++) {
		mx=max(mx,(long long)v[i]*(long long)(n-i));
	}
	cout << mx << endl;
}