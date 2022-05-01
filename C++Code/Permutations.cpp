#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> odd,even;
	for (int i=N; i>=1; i--) {
		if (i%2==0) even.push_back(i);
		else odd.push_back(i);
	}
	if (N==1) cout << 1 << endl;
	else if (N<4 || abs(odd.back()-even.front())==1) {
		cout << "NO SOLUTION" << endl;
	}
	else {
		for (int i : odd) cout << i << ' ';
		for (int i=0; i<even.size(); i++) cout << even[i] << (i<even.size()-1 ? " " : "");
		cout << endl;
	}
}