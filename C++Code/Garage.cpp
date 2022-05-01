#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N,M; cin>>N>>M;
	vector<int> R(N+1),W(M+1);
	for (int i=1; i<=N; i++) cin>>R[i];
	for (int i=1; i<=M; i++) cin>>W[i];
	
	long long ANS=0;
	vector<int> parked(M+1);
	vector<bool> full(N+1);
	deque<int> dq;
	for (int i=0; i<2*M; i++) {
		string s; cin>>s;
		int num;
		if (s[0]=='-') {
			s.erase(s.begin(),s.begin()+1);
			num=stoi(s);
			full[parked[num]]=0;

			if (!dq.empty()) {
				int nextAval=0;
				for (int o=1; o<=N; o++) {
					if (!full[o]) {
						nextAval=o;
						break;
					}
				}
				num=dq.front(); dq.pop_front();
				parked[num]=nextAval;
				full[nextAval]=1;
			}
		}
		else {
			num=stoi(s);
			dq.push_back(num);

			int nextAval=0;
			for (int o=1; o<=N; o++) {
				if (!full[o]) {
					nextAval=o;
					break;
				}
			}
			if (nextAval!=0) {
				num=dq.front(); dq.pop_front();
				parked[num]=nextAval;
				full[nextAval]=1;
			}
		}
	}
	for (int i=1; i<=M; i++) {
		ANS+=W[i]*R[parked[i]];
	}
	cout << ANS << endl;
}