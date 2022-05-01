#include <bits/stdc++.h>
using namespace std;

int N,B,T;
vector<long long> V;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>B>>T;
	V=vector<long long>(N);
	for (int i=0; i<N; i++) {
		cin>>V[i];
	}
	int ans=0;
	for (int i=0; i<N; i++) {
		long long mx=INT_MIN, mn=INT_MAX;
		for (int o=i; o<N; o++) {
			mx=max(mx,V[o]);
			mn=min(mn,V[o]);
			long long dif=mx-mn;
			if (dif<=T && dif>=B) ans++;
		}
	}
	cout << ans << endl;
}