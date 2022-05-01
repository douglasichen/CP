#include <bits/stdc++.h>
using namespace std;

vector<int> V,IS;

bool sorter(int i, int j) {
	if (V[i]==V[j]) return i<j;
	return V[i]<V[j];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N,X; cin>>N>>X;
	V=vector<int>(N);
	IS=vector<int>(N);
	for (int i=0; i<N; i++) {
		cin>>V[i];
		IS[i]=i;
	}
	sort(IS.begin(), IS.end(), sorter);
	int l=0, r=N-1;
	while (l<r) {
		int a=IS[l], b=IS[r], sm=V[a]+V[b];
		if (sm==X) {
			cout << a+1 << ' ' << b+1 << endl;
			return 0;
		}
		else if (sm<X) {
			l++;
		}
		else {
			r--;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}