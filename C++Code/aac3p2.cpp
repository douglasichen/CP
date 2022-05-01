#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K,D; cin>>K>>D;
	vector<int> V(D);
	for (int i=0; i<D; i++) cin>>V[i];
	sort(V.begin(),V.end());

	string ans="";
	if (D==1) {
		if (V[0]==0) ans="-1";
		else {
			for (int i=0; i<K; i++) ans+=V[0]+'0';
		}
	}
	else {
		if (V[0]==0) {
			if (K>=2) {
				ans+=V[1]+'0';
				for (int i=0; i<K-2; i++) ans+='0';
				ans+=V[1]+'0';
			}
			else ans+=V[1]+'0';
		}
		else {
			for (int i=0; i<K; i++) ans+=V[0]+'0';
		}
	}
	cout << ans << endl;
}