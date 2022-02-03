#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


void solve(vector<ll> v) {
	vector<ll> vv(3);
	for (int i=0; i<3; i++) {
		int biggest = v[i];
		bool t = false;
		for (int o=0; o<3; o++) {
			if (o==i) continue;
			if (v[o] >= biggest) {
				biggest = v[o];
				t = true;
			}
		}
		if (t) biggest++;
		cout << biggest-v[i] << ' ';
	}
	cout<<endl;
}

int main() {
	int t; cin>>t;
	for (int i=0; i<t; i++) {
		vector<ll> v(3); cin>>v[0]>>v[1]>>v[2];
		solve(v);
	}
}