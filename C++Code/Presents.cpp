#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


void solve() {

}

int main() {
	int n; cin>>n;
	vi v(n+1);
	for (int i=1; i<=n; i++) {
		int inp; cin>>inp;
		v[inp] = i;
	}
	for (int i=1; i<=n; i++) cout<<v[i]<<' ';
	cout<<endl;
}