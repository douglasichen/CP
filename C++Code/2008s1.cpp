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
	pair<string,int> cold = {"", 201};
	string c = "";
	while (c != "Waterloo") {
		cin>>c;
		int temp; cin>>temp;
		if (temp < cold.S) {
			cold = {c, temp};
		}
	}
	cout<<cold.F<<endl;
}