#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	long long T; cin>>T;
	long long ans[T];
	for (long long i=0,W,H,K; i<T; i++) {
		cin>>W>>H>>K;
		vector<int> a,b,c,d;
		for (int o=0,inp; o<K; o++) cin>>inp,a.push_back(inp);
		cin>>K;
		for (int o=0,inp; o<K; o++) cin>>inp,b.push_back(inp);
		cin>>K;
		for (int o=0,inp; o<K; o++) cin>>inp,c.push_back(inp);
		cin>>K;
		for (int o=0,inp; o<K; o++) cin>>inp,d.push_back(inp);
		sort(a.begin(),a.end()); sort(b.begin(),b.end()); sort(c.begin(),c.end()); sort(d.begin(),d.end());
		long long ans1=max(a.back()-a.front(),b.back()-b.front())*H,ans2=max(c.back()-c.front(),d.back()-d.front())*W;
		ans[i]=max(ans1,ans2);
	}	
	for (long long i : ans) cout << i << endl;
}