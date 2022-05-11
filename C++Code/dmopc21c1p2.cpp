#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N);
	set<int,greater<int>> S;
	for (int i=0; i<N; i++) cin>>V[i],S.emplace(i);
	int other=0;
	for (int e : S) {
		for (int i=0; i<N; i++) {
			
		}
	}
}