#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> a,b;
	long long sA=0,sB=0;
	for (int i=N; i>0; i--) {
		if (sA<sB) {
			a.push_back(i);
			sA+=i;
		}
		else {
			b.push_back(i);
			sB+=i;
		}
	}
	if (sA==sB) {
		cout << "YES" << endl;
		cout << a.size() << endl; 
		for (int i : a) cout << i << ' ';
		cout << endl;
		cout << b.size() << endl;
		for (int i : b) cout << i << ' ';
		cout << endl;
	}
	else {
		cout << "NO" << endl;
	}
}