#include <bits/stdc++.h>
using namespace std;

void solve() {

}

bool sorter(vector<int> a, vector<int> b) {
	if (a[1]==b[1]) return a[0]<b[0];
	return a[1]<b[1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int X,N; cin>>X>>N;
	vector<vector<int>> V(N);
	for (int i=0; i<N; i++) {
		int t,f; cin>>t>>f;
		V[i]={t,f};
	}
	sort(V.begin(), V.end(), sorter);
	// for (vector<int> v : V) cout << v[0] << ' ' << v[1] << endl;
	
	int time=0;
	int ans=0;
	for (int i=0; i<N; i++) {
		int temp=V[i][0], f=V[i][1];
		temp-=time;
		f-=time;
		if (f<0) continue;
		int tdif=X-temp;

		bool ok=0;
		if (tdif>=0) {
			time++;
			ans++;
			ok=1;
		}
		else {
			tdif=abs(tdif);
			if (tdif<=f) {
				time+=tdif;
				ans++;
				ok=1;
			}
			else {
				// cout << tdif << " > " << f << endl;
			}
		}
		// if (ok) cout << "Can" << endl;
		// else cout << "Cant" << endl;
	}
	cout << ans << endl;
}