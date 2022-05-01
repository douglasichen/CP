#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	unsigned long long M;
	int N,Q; cin>>N>>M>>Q;
	vector<unsigned long long> psa(N+1);
	vector<vector<int>> mima(1e6+1,{INT_MAX,INT_MIN});
	for (int i=1,inp; i<=N; i++) {
		cin>>inp;
		psa[i]+=psa[i-1]+inp;
		mima[inp][0]=min(mima[inp][0],i);
		mima[inp][1]=max(mima[inp][1],i);
	}
	for (int i=0,p,k,a,b,c,d; i<Q; i++) {
		cin>>p>>k;
		a=mima[p][0]; b=mima[k][1]; c=mima[k][0]; d=mima[p][1];
		if ((a!=INT_MAX && b!=INT_MIN && a<=b && (psa[b]-psa[a-1])>=M*2) ||
			(c!=INT_MAX && d!=INT_MIN && c<=d && (psa[d]-psa[c-1])>=M*2)) {
			cout << "Enough" << endl;
		}
		else cout << "Not enough" << endl;
	}

}