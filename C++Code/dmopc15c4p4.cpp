#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	long long K;
	int N,Q; cin>>N>>K>>Q;
	vector<long long> psa(N+1);
	vector<vector<int>> at(2001);
	for (int i=1,inp; i<=N; i++) {
		cin>>inp;
		psa[i]+=psa[i-1]+inp;
		at[inp+1000].push_back(i);
	}
	for (int i=0; i<Q; i++) {
		int A,B,X,Y; cin>>A>>B>>X>>Y;
		A+=1000, B+=1000;
		bool ans=0;
		if (psa[Y]-psa[X-1]>K) {
			auto a=lower_bound(at[A].begin(), at[A].end(), X), b=lower_bound(at[B].begin(), at[B].end(), X);
			if (a!=at[A].end() && (*a)<=Y && b!=at[B].end() && (*b)<=Y) ans=1;
		}
		if (ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
}


