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
	vi ans;
	int score = 0;
	for (int i=0; i<2*n; i++) {
		char inp; cin>>inp;
		if (i<n) {
			ans.PB(inp);
		}
		else {
			if (inp==ans[i-n]) {
				score++;
			}
		}
	}
	cout<<score<<endl;
}