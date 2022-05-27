#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<vector<int>> V(N,vector<int>(2));
	ll cnt=0;
	for (int i=0; i<N; i++) {
		cin>>V[i][0]>>V[i][1];
		assert(V[i][0]==0);
	}

	auto cmp1=[&](const int &a, const int &b){return V[a][0]<V[b][0];};
	set<int,decltype(cmp1)> A(cmp1);
	vector<int> B;
	for (int i=0; i<N; i++) A.emplace(i), B.push_back(i);

	auto cmp2=[&](const int &a, const int &b){return V[a][1]<V[b][1];};
	sort(B.begin(),B.end(),cmp2);

	ll sm=0, ans, mDif;
	int mx=0, dif=B[0];
	for (int i=0; i<N; i++) {
		mx=max(mx,V[B[i]][1]);
		if (V[dif][0]-V[dif][1]>V[B[i]][0]-V[B[i]][1]) dif=B[i];
		sm+=V[B[i]][1];

		
		mDif=sm+(V[dif][0]-V[dif][1]);
		if (A.empty()) ans=mDif;
		else ans=min(mDif, sm-mx+V[*A.begin()][0]);
		cout << ans << endl;
		A.erase(B[i]);
	}
}