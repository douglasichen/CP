#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	for (int i=0,N,R,B; i<T; i++) {
		cin>>N>>R>>B;
		int sz=ceil((float)R/(float)(B+1));
		if (sz*(B+1)<R) sz++;
		if ((sz-1)*(B+1)==R) sz--;
		string s="";
		int r=0,left=B+1;
		while (s.size()<N) {
			if (R-r<=left) sz=1;
			for (int i=0; i<sz; i++) {
				if (r==R) break;
				s+='R';
				r++;
			}
			left--;
			s+='B';
		}
		for (int i=0; i<N; i++) cout << s[i];
		cout << endl;

	}	
}