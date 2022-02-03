#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

vi l(101);
vi s(101);

int solve(int p, int n) {
	int ns = p+n;
	// cout << "ns: " << ns << endl;
	if (ns>100) return p;
	
	if (l[ns]!=0) ns = l[ns];
	if (s[ns]!=0) ns = s[ns];
	return ns;
}

int main() {
	l[9] = 34;
	l[40]=64;
	l[67]=86;
	s[99]=77;
	s[90]=48;
	s[54]=19;

	int p = 1;
	int n = -1;
	while (n!=0) {
		// cout << "Enter sum of dice:" << endl;
		cin>>n;
		if (n==0) {
			cout << "You Quit!" << endl;
			break;
		}

		int nextSpace = solve(p, n);
		cout << "You are now on square " << nextSpace << endl;
		
		if (nextSpace == 100) {
			cout<<"You Win!"<<endl;
			break;
		}
		p = nextSpace;
	}
}