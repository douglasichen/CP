#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	int a=0,b=0;
	for (int i=0,inp; i<N; i++) {
		cin>>inp;
		if (inp==1) a++;
		else if (inp==2) b++;
	}
	if (a-1>b) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> ans;
	while (a||b) {
		if (a) {
			ans.push_back(1);
			a--;
		}
		if (b) {
			ans.push_back(2);
			b--;
		}
	}
	for (int i : ans) cout << i << ' ';
	cout << endl;
}