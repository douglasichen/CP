#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	vector<vector<int>> T(K),F(K);
	for (int i=0; i<N; i++) {
		for (int o=0; o<K; o++) {
			char c; cin>>c;
			if (c=='T') T[o].push_back(i);
			else F[o].push_back(i);
		}
	}
	vector<int> scr(N);
	int mn=0;
	for (int i=0; i<K; i++) {
		int a=0,b=0;
		for (int o : T[i]) if (scr[o]==mn) a++;
		for (int o : F[i]) if (scr[o]==mn) b++;
		if (a>b) {
			if (b==0) mn++;
			for (int o : T[i]) scr[o]++;
		}
		else {
			if (a==0) mn++;
			for (int o : F[i]) scr[o]++;
		}
	}
	cout << mn << endl;
}