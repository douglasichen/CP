#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

vi vote = {2007, 2, 27};

string solve(int y, int m, int d) {
	if (vote[0] - y < 18) return "No";
	if (vote[0] - y > 18) return "Yes";
	if (vote[1] < m) return "No";
	if (vote[1] > m) return "Yes";
	if (vote[2] < d) return "No";
	if (vote[2] >= d) return "Yes";
	return "No";
}

int main() {
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		int y,m,d; cin>>y>>m>>d;
		cout<<solve(y,m,d)<<endl;
	}
}