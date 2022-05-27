#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> A(N+1),B(N+1);
	for (int i=1; i<=N; i++) cin>>A[i];
	for (int i=1; i<=N; i++) cin>>B[i];

	bool b=1;
	vector<int> p1(N+1),p2(N+1);
	for (int i=1; i<=N; i++) p1[i]=p1[i-1]+A[i];
	for (int i=1; i<=N; i++) p2[i]=p2[i-1]+B[i];
	for (int i=1; i<=N; i++) {
		if (p1[i]<p2[i]) {
			b=0;
			break;
		}
	}


	if (!b || p1[N]!=p2[N]) {
		cout << -1 << endl;
		return 0;
	}
	
	vector<int> num0={0};
	for (int i=1; i<=N; i++)
		if (!A[i])
			num0.push_back(i);
	
	vector<vector<int>> G;
	int frm=1;
	for (int i=1; i<N; i++) {
		if (B[i]) frm=i+1;
		if (!B[i] && B[i+1]) {
			G.push_back({frm,i});
		}
	}
	frm=1;
	vector<vector<int>> ans;
	int cnt=0;
	for (vector<int> v : G) {
		int a=v[0], b=v[1], sz=b-a+1;
		cnt+=sz;
		if (num0[cnt]-a+1==sz) continue;
		ans.push_back({a, num0[cnt]});
		frm=num0[cnt]+1;
	}
	cout << ans.size() << endl;
	for (vector<int> a : ans) cout << a[0] << ' ' << a[1] << endl;

}