#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	vector<int> V(N),big(1e6+1),fac(1e6+1),has(1e6+1),sorted,uniq;
	int ones=0;
	for (int i=0; i<N; i++) {
		cin>>V[i];
		if (!has[V[i]]) uniq.push_back(V[i]);
		has[V[i]]++;
		ones+=V[i]==1;
	}
	for (int i : uniq) {
		i-=K;
		if (i<=1) continue;
		for (int o=1; o<=sqrt(i); o++) {
			if (has[o] && i%o==0) {
				fac[i]+=has[o];
				if (i/o!=o) {
					fac[i]+=has[i/o];
					// cout << i << "," << i/o << endl;
				}
				// cout << i << "," << o << endl;
			}
		}
	}
	for (int i=1; i<=1e6; i++) fac[i]-=fac[i]!=0;
	sorted=V;
	sort(sorted.begin(),sorted.end(),greater<int>());
	for (int i=sorted.size()-1; i>=0; i--) {
		big[sorted[i]]=max(big[sorted[i]],i);
	}
	for (int i=0; i<N; i++) {
		int ans=big[V[i]]*(V[i]==K),t=V[i]-K;
		if (K!=1 && V[i]%K==0 || t<=0) {
			cout << ans << ' ';
			continue;
		}
		ans+=fac[t];
		if (!K) ans+=ones;
		cout << ans << ' ';
	}
	cout << endl;
	// for (int i=1; i<=10; i++) cout << fac[i] << ' ';
	// cout << endl;
}