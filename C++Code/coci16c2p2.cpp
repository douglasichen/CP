#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	ll N,M,K,X; cin>>N>>M>>K>>X;
	
	ll at=X-1;
	vector<ll> loc(M);
	for (int i=0; i<M; i++) {
		loc[M-i-1]=at%K;
		at/=K;
	}

	string S; cin>>S;
	vector<char> place(M);
	for (int i=0; i<M; i++) {
		string s; cin>>s; sort(s.begin(),s.end());
		place[i]=s[loc[i]];
	}
	int e=0;
	for (int i=0; i<N; i++) {
		if (S[i]=='#') {
			S[i]=place[e];
			e++;
		}
	}
	cout << S << endl;


}