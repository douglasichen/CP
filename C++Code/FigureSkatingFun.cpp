#include <bits/stdc++.h>
using namespace std;

int solve(int n, int s[], int oSum) {
	if (n==1) return -1;
	int left=0, right=oSum;
	for (int i=0; i<n; i++) {
		left += s[i];
		right -= s[i];
		if (left==right) return i+1;
		// cout << "left: " << left << endl;
		// cout << "right: " << right << endl;
	}
	return -1;
}

int main() {
	int n; cin>>n;
	int s[n];
	for (int i=0; i<n; i++) cin>>s[i];
	int oSum=0;	for (int i : s) oSum+=i;

	int ans = solve(n,s,oSum);
	
	if (ans!=-1) {
		cout << ans << endl;
	}
	else {
		cout << "Andrew is sad." << endl;
	}

}