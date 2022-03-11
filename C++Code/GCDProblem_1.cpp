#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n) {
	n--;
	int d=n/2;
	if (d*2==n) {
		if (d%2==0) return {d+1,d-1,1};
		else return {d+2,d-2,1};
	}
	else {
		return {d,d+1,1};
	}

}

int main() {
	int t; cin>>t;
	vector<int> ans[t];
	for (int i=0; i<t; i++) {
		int n; cin>>n;
		ans[i]=solve(n);
	}
	for (vector<int> i : ans) {
		for (int e : i) cout << e << " ";
		cout << endl;
	} 
}