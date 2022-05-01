#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	double A,B; cin>>A>>B;
	string s; cin>>s;
	int N=s.size();
	int ans=0;
	for (int a=0; a<N; a++) {
		int c0=0,c1=0;
		for (int b=a; b<N; b++) {
			c0+=s[b]=='0';
			c1+=s[b]=='1';
			double dif=abs(c0-c1), sz=b-a+1;
			double res=dif/sz*100;
			if (ceil(res)*sz<=dif*100) res=ceil(res);
			if (res>=A && res<=B) ans++;
		}
	}
	cout << ans << endl;
}