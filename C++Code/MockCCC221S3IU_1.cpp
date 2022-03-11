#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N; cin>>N;
	int cnt=0;
	int pb=0;
	for (int i=0; i<N*2; i++) {
		char inp; cin>>inp;
		bool b=(inp=='I' ? 1 : 0);
		if (i!=0) {
			if (!b && pb) cnt++;
		}
		pb=b;
	}
	cout << N-cnt << endl;
}