#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

<<<<<<< HEAD
void solve() {

}

=======
>>>>>>> 8a463f770f4125afabefad2860dbd9e821987674
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

<<<<<<< HEAD
	int T=10;
=======
	int T=1;
>>>>>>> 8a463f770f4125afabefad2860dbd9e821987674
	while (T--) {
		int N,ans=0; cin>>N;
		vector<int> V(N);
		for (int i=0; i<N; i++) cin>>V[i];
		
		int find=0;
		for (int i=0; i<N; i++) {
			if (V[i]==N) {
				int val=N;
				for (int at=i; val; at--, val--) {
					if (at<0 || V[at]!=val) {
						find=val;
						break;
					}
				}
				break;
			}
		}
		for (; find; find--) {
			int at;
			for (int i=0; i<N; i++) if (V[i]==find) at=i;
			ans+=at;
			for (; at; at--) swap(V[at],V[at-1]);
		}
		cout << ans << endl;
	}	
}