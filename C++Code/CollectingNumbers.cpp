#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	unordered_map<int,bool> at;
	for (int i=0; i<N; i++) {
		int inp; cin>>inp;
		if (inp==1) at[inp]=1;
		else {
			if (at[inp-1]==0) at[inp]=1;
			else {
				at.erase(inp-1);
				at[inp]=1;
			}
		}
	}	
	cout << at.size() << endl;
}