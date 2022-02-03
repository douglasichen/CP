#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int n; cin>>n;
	int sum=0;
	for (int i=0; i<n; i++) {
		int inp; cin>>inp;
		sum+=inp;
	}
	float av = (float) sum / (float) n;

	if (av==0) {
		cout << "0.0" << endl;
	}
	else {
		int aa = round(av*10);
		string s = to_string(aa);

		for (int i=0; i<s.size(); i++) {
			if (i==s.size()-1) cout << '.';
			cout << s[i];
		}
		cout << endl;
	}
}