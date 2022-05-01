#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N=1e5;
	int M=2e5;
	cout << N << " " << M << endl;
	int end=N;
	for (int i=1; i<=N; i++) {
		if (end-1<=i) break;
		cout << i << " " << end << " " << 1;
		end-=2;
		M--;
		if (M==0) break;
		cout << endl;
	}

}