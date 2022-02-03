#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef vector<vector<int>> vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(x,n) for(int x = 0; x < n; ++x)

#define printV(v) FOR(x,v.size()) cout<<v[x]<<' '; cout<<endl;


void solve() {

}

int main() {
	int n; 
	string s="";
	cin>>n;
	deque<int> ip;
	deque<int> pni;
	bool isI[n*2+1];
	bool isU[n*2+1];

	for (int i=0; i<2*n; i++) {
		char c; cin>>c;
		s+=c;

		char need=(i%2==1 ? 'U' : 'I');
		if (c=='I') {
			isI[i]=true;
			if (c!=need)
				ip.push_back(i);
		}
		if (c=='U') {
			isU[i]=true;
			if (c!=need)
				pni.push_back(i);
		}
	}
	ll sum=0;
	while (!ip.empty() && !pni.empty()) {
		int I = ip.back();
		int U = pni.back();
		int dis = abs(I-U);
		sum+=dis;
		ip.push_front(U);

		char need = (I%2==1 ? 'U' : 'I');
		if (need==s[I]) {
			pni.push_front(I);
		}

		ip.pop_back();
		pni.pop_back();
	}
	cout << sum << endl;
}