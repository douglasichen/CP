#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	hash<string> h;
	int X; cin>>X;
	string S; cin>>S;
	vector<string> V={"",S};
	unordered_map<size_t,int> M; M[h(S)]=1;
	for (int i=2; i<X+2; i++) {
		string s="";
		for (int o=0; o<S.size(); o+=2) s+=S[o];
		for (int o=(S.size()%2 ? S.size()-2 : S.size()-1); o>=1; o-=2) s+=S[o];
		size_t hashed=h(s);
		if (M[hashed]) {
			int p=i-M[hashed], at=(X+1-M[hashed])%p+M[hashed];
			cout << V[at] << endl;
			return 0;
		}
		V.push_back(s);
		M[hashed]=i;
		S=s;
	}
	cout << S << endl;
}