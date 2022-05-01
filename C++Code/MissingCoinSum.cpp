#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N);	
	for (int i=0; i<N; i++) cin>>V[i];
	sort(V.begin(),V.end());
	long long r=1;
	for (int i : V) {
		if (i>r) break;
		r+=i;
	}
	cout << r << endl;
}