#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> psa(N+1);
	for (int i=1,inp; i<=N; i++) {
		cin>>inp;
		psa[i]=psa[i-1]+inp;
	}
	int T; cin>>T;
	for (int i=0,X; i<T; i++) {
		int ans=0;
		cin>>X;
		for (int a=0,b=1; b<=N; b++) {
			while (psa[b]-psa[a]>X) a++;
			ans+=psa[b]-psa[a]==X;
		}
		cout << ans << ' ';
	}
	cout << endl;
}