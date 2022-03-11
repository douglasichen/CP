#include <bits/stdc++.h>
using namespace std;

void solve() {

}

bool sorter(int a, int b) {
	return a<b;
}

int main() {
	int n; cin>>n;
	int v[n];
	for (int i=0; i<n; i++) cin>>v[i];

	priority_queue<int, vector<int>, decltype(&sorter)> p(sorter);
	for (int i : v) p.push(i);
	
	while (!p.empty()) {
		cout << p.top() << " ";
		p.pop();
	}
	cout << endl;
}