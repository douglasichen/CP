#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

vector<pi> p = {
	{0,1},
	{0,2},
	{1,2},
	{1,0},
	{2,0},
	{2,1},
}

int solve(vector<ll> a) {
	ll minD = pow(10,8)+1;
	for (int i=0; i<p.size(); i++) {
		int p1 = p[i].F, p2 = p[i].S;
		vector<ll> newA = a;
		newA[p1]-=1;
		
	}
}

int main() {
	ll n; cin>>n;
	for (int i=0; i<n; i++) {
		vector<ll> a(3); cin>>a[0]>>a[1]>>a[2];
		cout << solve(a) << endl;
	}
}