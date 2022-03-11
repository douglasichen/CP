#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int N1,N2; cin>>N1>>N2;
	unordered_map<char,bool> op;
	vector<char> V(N1);
	for (int i=N1-1; i>=0; i--) {
		cin>>V[i];
	}
	for (int i=0; i<N2; i++) {
		char c; cin>>c;
		op[c]=1;
		V.push_back(c);
	}
	int T; cin>>T;
	while (T) {
		vector<char> nV=V;
		for (int i=0; i<V.size()-1; i++) {
			int a=V[i], b=V[i+1];
			if (op[a]==0 && op[b]==1) {
				swap(nV[i],nV[i+1]);
			}
		}
		V=nV;
		T--;
	}
	for (char c : V) cout << c;
	cout << endl;
}