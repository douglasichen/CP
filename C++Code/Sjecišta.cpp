#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	float n; cin>>n;
	n-=2;
	int ans=round(0.5*(n-1)*(n*n - 2*n + 2));
	cout << ans << endl;	
}