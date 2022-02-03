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
	int a,b; cin>>a>>b;
	int c = 0;
	int n = ceil(pow(a,1/6.0));
	while (pow(n,6)<=b) {
		c++;
		n++;
	}
	cout<<c<<endl;
}