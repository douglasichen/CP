#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N,Q; cin>>N>>Q;
	vector<int> V(N);
	
	unordered_map<string,int> s2i;
	s2i["square"]=1;
	s2i["circle"]=2;
	s2i["triangle"]=3;

	for (int i=0; i<Q; i++) {
		string com,shape; cin>>com>>shape;
		int ind; cin>>ind; ind--;
		int num=s2i[shape];
		if (com=="set") {
			V[ind]=num;
		}
		else {
			cout << (V[ind]==num) << endl;
		}
	}
}