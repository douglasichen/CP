#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int n; cin>>n;
	int ans=0;
	int right=min(5,n);
	int left=max(n-5,0);
	for (; left<=right; left++) {
		right--;
		ans++;
	}
	cout << ans << endl;
}