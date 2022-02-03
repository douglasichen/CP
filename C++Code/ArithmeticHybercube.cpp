#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int n; cin>>n;
	vector<int> v(n);
	for (int i=0; i<n; i++) cin>>v[i];
	sort(v.begin(), v.end());
	for (int i : v) cout << i << ' ';
	cout << endl;
}