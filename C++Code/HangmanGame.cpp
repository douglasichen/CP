#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string A; getline(cin,A);
	string ans="";
	set<char> S;
	for (char c : A) if (c!=' ') S.emplace(c);
	int N=S.size(),steps=(*S.begin())-'A';
	ans+=(*S.begin());
	S.erase(S.begin());
	while (ans.size()<N) {
		char c=ans.back();
		pair<char,int> best={0,200};
		for (auto it=S.begin(); it!=S.end(); it++) {
			int a=c,b=(*it);
			if (a>b) swap(a,b);
			int dis=min(b-a,a+26-b);
			if (dis<best.second) best={(*it),dis};
		}
		ans+=best.first;
		steps+=best.second;
		S.erase(best.first);
	}
	cout << N+steps << endl;
	cout << ans << endl;
}