#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	long long K; cin>>K; K++;
	vector<int> V;
	int a=1;
	bool bad=0;
	for (long long i=2,j; i*i<=K; i++) {
		while (K%i==0) {
			j=i-1;
			if (V.size()+j>1e5) bad=1;
			while (!bad && j) V.push_back(a),j--;
			a++;
			K/=i;
			if (bad) break;
		}
		if (bad) break;
	}
	if (!bad && K>1) {
		K--;
		if (V.size()+K>1e5) bad=1;
		else while (K) K--,V.push_back(a);
	}
	
	if (bad) cout << "Sad Chris" << endl;
	else {
		cout << V.size() << endl;
		for (int i=0; i<V.size(); i++) cout << V[i] << (i<V.size()-1 ?  " " : "");
		cout << endl;
	}
}