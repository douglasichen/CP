#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	for (int i=0; i<T; i++) {
		int N; cin>>N;
		set<int> has;
		int dif=0;
		for (int j=0; j<N; j++) {
			int inp; cin>>inp;
			if (has.find(inp) == has.end()) dif++;
			has.insert(inp);
		}
		
		for (int j=0; j<dif; j++) cout << dif << ' ';
		for (int j=dif+1; j<=N; j++) cout << j << (j<N ? ' ' : '\n');
	}
}