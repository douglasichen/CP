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
	int s=0, t=0;
	cin.ignore();
	for (int i=0; i<n; i++) {
		string line; getline(cin,line);
		for (char c : line) {
			if (c=='s'||c=='S') s++;
			if (c=='t'||c=='T') t++;
		}
	}
	if (s>=t) {
		cout<<"French"<<endl;
	}
	else {
		cout<<"English"<<endl;
	}
}