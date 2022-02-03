#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	deque<char> ans;
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		char c; cin>>c;
		if (ans.size()==0) ans.push_back(c);
		else if (ans.size()==1) {
			if (c<ans[0]) ans.push_front(c);
			else ans.push_back(c);
		}
		else {
			char right = ans.back(), left = ans.front();
			if (c<=left) ans.push_front(c);
			else ans.push_back(c);
		}
	}
	while (!ans.empty()) {
		cout << ans.front();
		ans.pop_front();
	}
	cout << endl;
}