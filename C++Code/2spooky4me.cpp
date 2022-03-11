#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int N,L,S; cin>>N>>L>>S;
	int lost=0;
	unordered_map<int,int> houses;
	unordered_map<int,bool> isLost;
	for (int i=0; i<N; i++) {
		int a,b,s; cin>>a>>b>>s;
		for (int o=a; o<=b; o++) {
			if (isLost[o]) continue;
			houses[o]+=s;
			if (houses[o]>=S) {
				if (!isLost[o]) {
					lost++;
					isLost[o]=1;
				}
			}
		}
	}

	cout << L-lost << endl;
}