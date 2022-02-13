#include <bits/stdc++.h>
using namespace std;

bool solve(int n, stack<int> s1) {
	int next=1;
	stack<int> s2;

	while (s1.size() + s2.size() > 0) {
		if (!s1.empty()) {
			if (s1.top()==next) {
				s1.pop();
				next++;
			}
			else {
				if (!s2.empty()) {
					if (s2.top()==next) {
						s2.pop();
						next++;
					}
					else {
						s2.push(s1.top());
						s1.pop();
					}
				}
				else {
					s2.push(s1.top());
					s1.pop();
				}
			}
		}
		else {
			if (!s2.empty()) {
				if (s2.top()==next) {
					s2.pop();
					next++;
				}
				else {
					break;
				}
			}
		}
	}

	return (s1.empty() && s2.empty());
}

int main() {
	int t; cin>>t;
	bool ans[t];
	for (int i=0; i<t; i++) {
		int n; cin>>n;
		stack<int> s;
		for (int o=0; o<n; o++) {
			int inp; cin>>inp;
			s.push(inp);
		}
		ans[i]=solve(n,s);
	}
	for (bool i : ans)
		cout << (i ? 'Y' : 'N') << endl;	
}