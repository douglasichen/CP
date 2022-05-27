#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


int N,Q;
vector<long long> T;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>Q;
	T.assign(2*N,0);
	for (int i=0; i<N; i++) cin>>T[N+i];
	// build seg tree
	for (int i=N-1; i>0; i--) T[i]=T[i<<1]+T[i<<1|1];

	vector<long long> ans;
	for (int i=0; i<Q; i++) {
		int x,a,b; cin>>x>>a>>b;
		a--;
		if (x==1) {
			// modify pos a to val b
			for (T[a+=N]=b; a>1; a>>=1) T[a>>1]=T[a]+T[a^1];
		}
		else { 
			// answer query sum of range a->b
			long long res=0;
			for (a+=N, b+=N; a<b; a>>=1, b>>=1) {
				if (a&1) res+=T[a++];
				if (b&1) res+=T[--b];
			}
			ans.push_back(res);
		}
	}
	for (long long i : ans) cout << i << endl;
}