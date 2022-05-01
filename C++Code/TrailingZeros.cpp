#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	long long N; cin>>N;
	long long ans=0;
	long long twos=0,fives=0;
	for (int e=1; 1<<e<=N; e++) {
		long long d=1<<e;
		twos+=N/d;
	}
	for (int e=1; 1<<e<=N; e++) {
		long long d=pow(5,e);
		fives+=N/d;
	}
	cout << min(twos,fives) << endl;
}