#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	unsigned long long ans=0;
	vector<vector<int>> X,Y;
	for (int i=0,x,y; i<N; i++) {
		cin>>x>>y;
		ans+=abs(x); ans+=abs(y);
		X.push_back({x,0});
		Y.push_back({y,0});
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	for (int i=0; i<N; i++) X[i][1]=i, Y[i][1]=i;
	int mx=0,my=0;
	for (int i=0; i<M; i++) {
		char c; cin>>c;
		if (c=='S') {
			my++;
			auto a=lower_bound(Y.begin(),Y.end(),vector<int>{my,-1});
			if (a!=Y.end()) {
				int p=(*a)[1];
				ans+=p;
				ans-=N-p;
			}
			else ans+=N;
		}
		else if (c=='J') {
			my--;
			auto a=upper_bound(Y.begin(),Y.end(),vector<int>{my,INT_MAX});
			if (a!=Y.end()) {
				int p=(*a)[1];
				ans+=N-p;
				ans-=p;
			}
			else ans-=N;
		}
		else if (c=='I') {
			mx++;
			auto a=lower_bound(X.begin(),X.end(),vector<int>{mx,-1});
			if (a!=X.end()) {
				int p=(*a)[1];
				ans+=p;
				ans-=N-p;
			}
			else ans+=N;
		}
		else {
			mx--;
			auto a=upper_bound(X.begin(),X.end(),vector<int>{mx,INT_MAX});
			if (a!=X.end()) {
				int p=(*a)[1];
				ans+=N-p;
				ans-=p;
			}
			else ans-=N;
		}
		cout << ans << endl;
	}
}