#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<vector<ll>> P(N,vector<ll>(2));
	for (int i=0; i<N; i++) cin>>P[i][0]>>P[i][1];

	vector<vector<ll>> V;
	for (int i=0; i<N-1; i++) {
		for (int o=i+1; o<N; o++) {
			ll mx=(P[i][0]+P[o][0])/2, my=(P[i][1]+P[o][1])/2, rmx=(P[i][0]+P[o][0])%2, rmy=(P[i][1]+P[o][1])%2;
			ll d=pow(P[i][0]-P[o][0],2)+pow(P[i][1]-P[o][1],2); 
			V.push_back({mx,my,rmx,rmy,d,P[i][0],P[i][1],P[o][0],P[o][1]});
		}
	}
	sort(V.begin(),V.end());
	ll ans=0;
	vector<vector<int>> G;
	int start=0;
	for (int i=1; i<V.size(); i++) {
		if (V[i][0]!=V[i-1][0] || V[i][1]!=V[i-1][1] || V[i][2]!=V[i-1][2] || V[i][3]!=V[i-1][3] || V[i][4]!=V[i-1][4]) {
			int last=i-1;
			if (last-start+1>=2) G.push_back({start,last});
			start=i;
		}
	}
	for (vector<int> p : G) {
		int a=p[0], b=p[1];
		for (int i=a; i<b; i++) {
			for (int o=a+1; o<=b; o++) {
				vector<ll> p1={V[i][5],V[i][6]}, p2={V[o][5],V[o][6]}, p3={V[i][7],V[i][8]}, p4={V[o][7],V[o][8]};
				vector<vector<ll>> pts={p1,p2,p3,p4};
				ll A=abs(p1[0]-p2[0])*abs(p1[1]-p2[1]),B=abs(p2[0]-p3[0])*abs(p2[1]-p3[1]);

				ll y1=LLONG_MAX,y2=LLONG_MIN,x1=LLONG_MAX,x2=LLONG_MIN;
				for (vector<ll> p : pts) y1=min(y1,p[0]), y2=max(y2,p[0]), x1=min(x1,p[1]), x2=max(x2,p[1]);

				ll C=abs(y2-y1)*abs(x2-x1),area=C-A-B;
				ans=max(ans,area);
			}
		}
	}

	// for (int i=0; i<V.size()-1; i++) {
	// 	for (int o=i+1; o<V.size(); o++) {
	// 		if (V[i][0]==V[o][0] && V[i][1]==V[o][1] && V[i][6]==V[o][6] && V[i][7]==V[o][7] && V[i][8]==V[o][8]) {
	// 			vector<ll> p1={V[i][2],V[i][3]}, p2={V[o][2],V[o][3]}, p3={V[i][4],V[i][5]}, p4={V[o][4],V[o][5]};
	// 			vector<vector<ll>> pts={p1,p2,p3,p4};
	// 			ll A=abs(p1[0]-p2[0])*abs(p1[1]-p2[1]),B=abs(p2[0]-p3[0])*abs(p2[1]-p3[1]);

	// 			ll y1=LLONG_MAX,y2=LLONG_MIN,x1=LLONG_MAX,x2=LLONG_MIN;
	// 			for (vector<ll> p : pts) y1=min(y1,p[0]), y2=max(y2,p[0]), x1=min(x1,p[1]), x2=max(x2,p[1]);

	// 			ll C=abs(y2-y1)*abs(x2-x1),area=C-A-B;
	// 			ans=max(ans,area);
	// 		}
	// 	}
	// }
	cout << ans << endl;

}