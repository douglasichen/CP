#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<int> v) {
	vector<int> ans(n);
	unordered_map<int> citCount;
	for (int i=0; i<n; i++) {
		int cit=v[i];
		citCount[cit]++;
		
	}
	return ans;
}

int main() {
	int t; cin>>t;
	vector<vector<int>> ans(t);
	for (int i=0; i<t; i++) {
		int n; cin>>n;
		vector<int> v(n);
		for (int p=0; p<n; p++) {
			cin>>v[p];
		}
		ans[i]=solve(n,v);
	}
	int i=1;
	for (vector<int> v : ans) {
		cout << "Case #" << i << ": ";
		for (int l : v) cout << l << ' ';
		cout << endl;
		i++;
	}
}