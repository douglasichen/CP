#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N; N++;
	int bd=1;
	while (bd) {
		string s=to_string(N);
		vector<bool> H('9'+1);
		bool e=0;
		for (int i=0; i<s.size() && e==0; i++) {
			char c=s[i];
			if (H[c]) N++,e=1;
			else H[c]=1;
		}
		if (!e) break;
	}
	cout << N << endl;
}