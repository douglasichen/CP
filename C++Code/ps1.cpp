#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int n; cin>>n;
	vector<int> a(n),b(n);
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	for (int i=0; i<n; i++) {
		cin>>b[i];
	}
	int s1=0,s2=0;
	int ans=0;
	for (int i=0; i<n; i++) {
		s1+=a[i];
		s2+=b[i];
		if (s1==s2) ans=max(i+1,ans);
	}
	cout << ans << endl;


}