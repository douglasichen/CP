#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int cnt=0;
	for (unsigned long long i=1; i<=1000; i++) {
		unsigned long long a=3*((2*i-1)*powl(3,i)+1)/4, b=0;
		for (unsigned long long o=1; o<=i; o++) b+=i*powl(3,o);
		if (a!=b) {
			cout << i << ' ';
			cnt++;
		}
		if (cnt==10) break;
	}	
	cout << endl;
}