#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> sub(vector<ll> a, vector<ll> b) {
	return {a[0]-b[0],a[1]-b[1]};
}

vector<ll> recip(vector<ll> a) {
	return {-a[1],a[0]};
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<vector<ll>> P(N,vector<ll>(2));
	auto cmp=[](vector<ll> a, vector<ll> b) {
		if (a[1]) return a[0]*b[1]<b[0]*a[1];
		return false;
	};
	vector<multiset<vector<ll>,decltype(cmp)>> 
	S(N,multiset<vector<ll>,decltype(cmp)>(cmp));

	for (int i=0; i<N; i++)	cin>>P[i][1]>>P[i][0];
	sort(P.begin(),P.end());

	for (int i=0; i<N; i++) {
		for (int o=0; o<N; o++) {
			if (i!=o) {
				vector<ll> sl=sub(P[o],P[i]);
				S[i].emplace(vector<ll>{sl[0],sl[1],o});
			}
		}
	}
	for (vector<ll> i : P) cout << "(" << i[0] << "," << i[1] << ") ";
	for (auto s : S) {
		for (vector<ll> i : s) {
			cout << "(" << i[0] << "," << i[1] << "," << i[2] << ") ";
		}
		cout << endl;
	}

	// long long ans=0;
	// for (int i=0; i<N; i++) {
	// 	for (int o=0; o<N; o++) {
	// 		if (i!=o) {
	// 			//finding third points
	// 			vector<ll> sl1=sub(P[o],P[i]),sl2=recip(sl1);
	// 			auto it=lower_bound(S[o].begin(),S[o].end(),vector<ll>{sl2[0],sl2[1],-1},cmp);
	// 			while (it!=S[o].end()) {
	// 				int j=(*it)[2];
	// 				vector<ll> p3=P[j],p4=sub(p3,sl1);
	// 				if (binary_search(P.begin(),P.end(),p4)) {
	// 					ll y1=min(P[i][0],min(P[o][0],P[j][0])),y2=max(P[i][0],max(P[o][0],P[j][0]));
	// 					ll x1=min(P[i][1],min(P[o][1],P[j][1])),x2=max(P[i][1],max(P[o][1],P[j][1]));
	// 					ans=max(ans,abs(y2-y1)*abs(x2-x1));
	// 				}
	// 				it++;
	// 			}
	// 		}
	// 	}
	// } 
	// cout << ans << endl;
}