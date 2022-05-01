#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	vector<string> l={"sus","average","below average","can't eat dinner","don't come home","find a new home"};
	long long T; cin>>T;
	int ans[T];
	for (int i=0; i<T; i++) {
		double a,b; cin>>a>>b;
		long long g=ceil(a/b*100);
		if (g>100) ans[i]=0;
		else if (g==100) ans[i]=1;
		else if (g>=98) ans[i]=2;
		else if (g>=95) ans[i]=3;
		else if (g>=90) ans[i]=4;
		else ans[i]=5;
	}
	for (int i : ans) {
		cout << l[i] << endl;
	}
}