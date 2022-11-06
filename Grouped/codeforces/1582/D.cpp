#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		vector<int> A(N), B(N), C(N);
		for (int i=0; i<N; i++) cin>>A[i], B[i]=(A[i]<0 ? -1 : 1);
		for (int &i : A) i=abs(i);
		
		iota(C.begin(), C.end(), 0);
		sort(C.begin(), C.end(), [&](int &a, int &b) {
			return A[a]>A[b];
		});
		
		int sm=accumulate(A.begin(), A.end(), 0);
		for (int &i : C) {
			int b=(sm-A[i])/A[i];
			if (b>0) B[i]*=-b, sm-=A[i]+A[i]*abs(B[i]);
		}
		for (int &i : B) cout << i << ' '; cout << endl;
	}	
}