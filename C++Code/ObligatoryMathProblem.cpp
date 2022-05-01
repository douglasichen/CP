#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> V;

unsigned long long val(long long a) {
	unsigned long long sm=0;
	for (int i : V) sm+=abs(a-(long long)i);
	return sm;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	V=vector<long long>(N);

	long long left=INT_MAX, right=INT_MIN;
	for (int i=0; i<N; i++) {
		cin>>V[i];
		left=min(V[i],left);
		right=max(V[i],right);
	}

	// for (int i=left; i<=right; i++) cout << val(i) << ' ';
	// cout << endl;

	long long ans=(left+right)/2;
	while (left+1<right) {
		// cout << left << " vs " << right << endl;
		long long m1=(left+right)/2, m2=m1+1;
		unsigned long long v1=val(m1),v2=val(m2);
		if (v1<v2) {
			right=m1;
		}
		else {
			left=m2;
		}
	}
	unsigned long long a=val(left), b=val(right);
	if (a<b) {
		cout << left << endl;
	}
	else {
		cout << right << endl;
	}

}