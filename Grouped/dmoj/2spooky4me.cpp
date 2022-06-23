#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, L, S; cin>>N>>L>>S;
	vector<long long> T(L<<1);
	for (int i=0, a, b, v; i<N; i++) {
		cin>>a>>b>>v;
		for (a+=L-1, b+=L; a<b; a>>=1, b>>=1) {
			if (a&1) T[a]+=v, a++;
			if (b&1) T[b-1]+=v, b--;
		}
	}

}