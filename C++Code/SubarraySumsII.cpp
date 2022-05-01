#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,X; cin>>N>>X;
	vector<long long> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	
	long long ans=0;
	int a=0,b=0;
	long long v=V[0];
	while (a<N && b<N) {
		ans+=v==X;
		int dA=-V[a],dB;
		if (b==N-1) dB=0;
		else dB=V[b+1];
		
		if (v<=X) {
			if (dA>dB) {
				v+=dA;
				a++;
			}
			else {
				v+=dB;
				b++;
			}
		}
		else {
			if (dA<dB) {
				v+=dA;
				a++;
			}
			else {
				v+=dB;
				b++;
			}
		}
	}
	cout << ans << endl;
}