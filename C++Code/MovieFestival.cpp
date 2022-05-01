#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> starts, ends;
	for (int i=0; i<N; i++) {
		int a,b; cin>>a>>b;
		starts.push({a,i});
		ends.push({b,i});
	}

	vector<bool> used(N);
	int ans=0;
	int cur=0;
	while (!starts.empty() && !ends.empty()) {
		vector<int> a=starts.top(), b=ends.top();
		if (a[1]==b[1] && a[0]>=cur && !used[a[1]]) {
			cur=b[0];
			used[a[1]]=1;
			starts.pop();
			ends.pop();
			ans++;
		}
		else {
			while (!ends.empty() && used[ends.top()[1]]) ends.pop();
			if (ends.empty()) break;
			
			while (starts.top()[1]!=ends.top()[1]) {
				used[starts.top()[1]]=1;
				starts.pop();
			}
			used[starts.top()[1]]=1;
			if (starts.top()[0]<cur) {
				starts.pop();
				ends.pop();
				continue;
			}
			cur=ends.top()[0];
			starts.pop();
			ends.pop();
			ans++;
		}
	}
	cout << ans << endl;
}
