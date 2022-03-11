#include <bits/stdc++.h>
using namespace std;

int POWS[7];

char solve(int _a, int _b, int _c, int _d) {
	int aLen=to_string(_a).size(), cLen=to_string(_c).size();
	float a=(float)_a/POWS[aLen-1];
	float c=(float)_c/POWS[cLen-1];

	float b=_b+(aLen-1);
	float d=_d+(cLen-1);

	// cout << "\t:";
	// cout << a << ' ' << b << ' ' << c << " " << d << endl;

	if (b>d) return '>';
	else if (b<d) return '<';
	else {
		if (a>c) return '>';
		else if (a<c) return '<';
		else return '=';
	}
}

int main() {
	for (int i=0; i<7; i++) {
		POWS[i]=pow(10,i);
	}
	int t; cin>>t;
	char ans[t];
	for (int i=0; i<t; i++) {
		int a,b,c,d; cin>>a>>b>>c>>d;
		ans[i]=solve(a,b,c,d);
	}
	for (char i : ans) cout << i << endl;
}