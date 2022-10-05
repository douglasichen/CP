#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	long long ans=0;
	int N; cin>>N;
	vector<int> S;
<<<<<<< HEAD
	for (int i=0, e; i<N; i++) {
		cin>>e;

		int L=0, R=S.size()-1;
		while (L<R) {
			int M=L+R+1>>1;
			if (S[M]<=e) R=M-1;
			else L=M;
		}
		ans+=S.size()-L;

		while (S.size() && S.back()<e) S.pop_back();
		S.push_back(e);
=======
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
>>>>>>> 8a463f770f4125afabefad2860dbd9e821987674
	}
	cout << ans << endl;
}