#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


void solve(vector<string> a, vector<string> b, vector<string> c) {
	for (int one=0; one<a.size(); one++) {
		string s = a[one]+' ';
		for (int two=0; two<b.size(); two++) {
			string ss = s+b[two]+' ';
			for (int thr=0; thr<c.size(); thr++)  {
				string sss = ss+c[thr];
				cout<<sss<<'.'<<endl;
			}
		}
	}
}

int main() {
	int n; cin>>n;
	cin.ignore();
	for (int o=0; o<n; o++) {
		int a,b,c; cin>>a>>b>>c;
		vector<string> av(a),bv(b),cv(c);
		cin.ignore();
		for (int i=0; i<a; i++) getline(cin,av[i]);
		for (int i=0; i<b; i++) getline(cin,bv[i]);
		for (int i=0; i<c; i++) getline(cin,cv[i]);
		solve(av,bv,cv);
	}
}