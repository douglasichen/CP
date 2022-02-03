#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


bool solve(int n) {
	vi difs (32002);
	vi sums (32002);
	vi difInd;
	for (int i=1; i<=sqrt(n); i++) {
		if (n%i==0) {
			int dif = abs(i-n/i);
			int sum = i+n/i;
			difInd.PB(dif);
			difs[dif]=1;
			sums[sum]=1;
		}
	}
	for (int i=0; i<difInd.size(); i++) {
		int dif = difInd[i];
		if (difs[dif]==sums[dif]) {
			return true;
		}
	}
	return false;
}

int main() {
	int t; cin>>t;
	for (int i=0; i<t; i++) {
		int n; cin>>n;
		if (solve(n)) cout<<n<<" is nasty";
		else cout<<n<<" is not nasty";
		cout<<endl;
	}
}