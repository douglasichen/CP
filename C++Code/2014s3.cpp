#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


char solve(stack<int> cars) {
	stack<int> branch;
	int next = 1;
	while (cars.size()>0 || branch.size()>0) {
		if (cars.size()>0) {
			if (cars.top()==next) {
				cars.pop();
				next++;
			}
			else {
				if (branch.size()>0) {
					if (branch.top()==next) {
						branch.pop();
						next++;
					}
					else {
						branch.push(cars.top());
						cars.pop();
					}
				}
				else {
					branch.push(cars.top());
					cars.pop();
				}
			}
			
		}
		else {
			if (branch.size()>0) {
				if (branch.top()==next) {
					branch.pop();
					next++;
				}
				else return 'N';
			}
		}
		// cout<<"car top: "<<cars.top()<<endl;
		// cout<<"branch top: "<<branch.top()<<endl;
	}

	return 'Y';
}

int main() {
	int t; cin>>t;
	for (int i=0; i<t; i++) {
		int n; cin>>n;
		stack<int> cars;
		for (int o=0; o<n; o++) {
			int inp; cin>>inp;
			cars.push(inp);
		}
		cout<<solve(cars)<<endl;
	}

	// solve();
}