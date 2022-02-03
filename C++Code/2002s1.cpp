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
	vi t(4); int n; cin>>t[0]>>t[1]>>t[2]>>t[3]>>n;
	vector<vi> comb = {
		{0},{1},{2},{3},{0,1},{0,2},{0,3},{1,2},{1,3},{2,3},{0,1,2},{0,1,3},{0,2,3},{1,2,3},{0,1,2,3}
	};

	vector<vi> good;

	for (vi c : comb) {
		int sum=0;
		for (int i=0; i<c.size(); i++) {
			sum+=t[c[i]];
		}
		if (sum==n) {
			good.PB(c);
		}
	}

	for (vi c : good) {
		vi mat(4);
		for (int i : c) mat[i]=
		cout<<"# of Pink is: "
	}
}