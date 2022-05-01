#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<int> V;



struct cmp {
	bool operator() (const int &x, const int &y) const {
		if (V[x]==V[y]) return x>y;
		return V[x]<V[y];
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>M>>N;
	V=vector<int>(N);
	multiset<int, cmp> ms;
	for (int i=0; i<N; i++) {
		cin>>V[i];
		ms.emplace(i);
	}

	// for (auto i=ms.begin(); i!=ms.end(); i++) {
	// 	cout << V[*i] << ' ';
	// }
	// cout << endl;

	int K=0;
	for (; K<N; K++) {
		// if this index can be filled with another box farther to the right
		auto up=ms.lower_bound(K);
		cout << "lower bound for " << K << " is: " << V[*(up)] << endl;
	}
	cout << endl;
	cout << K << endl;


}