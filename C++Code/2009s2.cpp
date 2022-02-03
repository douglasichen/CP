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
	int r,l; cin>>r>>l;
	vector<vi> v(r, *(new vi(l)));
	for (int i=0; i<r; i++) {
		for (int o=0; o<l; o++) {
			cin>>v[i][o];
		}
	}
	int c = 0;
	vector<set<vi>> chan(l);
	for (int y=1; y<r; y++) {
		for (int x=0; x<l; x++) {
			int top = v[y-1][x];
			int bot = v[y][x];

			if (x>0) {
				if (chan[x-1].)
			}

			vi temp = {bot};
			if (top==bot && bot==1) temp.PB(0);
			if (top!=bot && bot==0) temp.PB(1);
			chan[x].push(temp);
		}
	}
	cout << c << endl;
}