#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	long long ans=0;
	int N; cin>>N;
	vector<int> S;
	map<int,int> F;
	for (int i=0, cnt, e; i<N; i++) {
		cin>>e;
		cnt=0;
		while (!S.empty() && S.top()<e) F[S.top()]--, S.pop(), cnt++;
		int add=cnt+F[e];
		if (add<S.size()+cnt) add++;
		ans+=add;
		F[e]++;
		S.push(e);
	}
	cout << ans << endl;
}