#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> sub(vector<ll> a, vector<ll> b) {
	return {a[0]-b[0],a[1]-b[1],0};
}

vector<ll> recip(vector<ll> a) {
	return {-a[1],a[0],a[2]};
}

ll gcd(ll a, ll b) {
	while (b) {
		a%=b;
		swap(a,b);
	}
	return a;
}

vector<ll> red(vector<ll> a) {
	if (a[0]==0) return {0,1};
	if (a[1]==0) return {1,0};
	vector<ll> sgn={a[0]>0 ? 1 : -1, a[1]>0 ? 1 : -1};
	if (sgn[0]*sgn[1]==1) sgn[0]=1,sgn[1]=1;
	if (sgn[1]==-1) swap(sgn[0],sgn[1]);
	
	a[0]=abs(a[0]); a[1]=abs(a[1]);
	ll D=gcd(a[0],a[1]);
	return {a[0]/D*sgn[0],a[1]/D*sgn[1],a[2]};
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<vector<ll>> P(N,vector<ll>(3));
	vector<multiset<vector<ll>>> S(N);

	for (int i=0; i<N; i++)	cin>>P[i][1]>>P[i][0];
	sort(P.begin(),P.end());

	for (int i=0; i<N; i++) {
		for (int o=0; o<N; o++) {
			if (i!=o) {
				vector<ll> sl=sub(P[o],P[i]);
				sl=red(sl);
				S[i].emplace(vector<ll>{sl[0],sl[1],o});
			}
		}
	}
	// for (vector<ll> i : P) cout << "(" << i[0] << "," << i[1] << ") ";
	// for (auto s : S) {
	// 	for (vector<ll> i : s) {
	// 		cout << "(" << i[0] << "," << i[1] << "," << i[2] << ") ";
	// 	}
	// 	cout << endl;
	// }

	vector<vector<bool>> did(N,vector<bool>(N));

	long long ans=0;
	for (int i=0; i<N-1; i++) {
		for (int o=i+1; o<N; o++) {
			if (i!=o && !did[i][o]) {
				//finding third point
				vector<ll> hop=sub(P[o],P[i]), sl=red(recip(hop));
				did[i][o]=1;

				auto it=lower_bound(S[o].begin(),S[o].end(),vector<ll>{sl[0],sl[1],-1});
				for (; it!=S[o].end() && (*it)[0]==sl[0] && (*it)[1]==sl[1]; it++) {
					int j=(*it)[2];	 did[o][j]=1;
					vector<ll> p1=P[i],p2=P[o],p3=P[j],p4=sub(p3,hop);
					vector<vector<ll>> pts={p1,p2,p3,p4};
 
					auto E=lower_bound(P.begin(),P.end(),p4);
					if (E!=P.end() && (*E)[0]==p4[0] && (*E)[1]==p4[1]) {
						did[j][E-P.begin()];
						ll A=abs(p1[0]-p2[0])*abs(p1[1]-p2[1]),B=abs(p2[0]-p3[0])*abs(p2[1]-p3[1]);

						ll y1=LLONG_MAX,y2=LLONG_MIN,x1=LLONG_MAX,x2=LLONG_MIN;
						for (vector<ll> p : pts) y1=min(y1,p[0]), y2=max(y2,p[0]), x1=min(x1,p[1]), x2=max(x2,p[1]);

						ll C=abs(y2-y1)*abs(x2-x1),area=C-A-B;
						ans=max(ans,area);
					}
				}
			}
		}
	} 
	cout << ans << endl;
}