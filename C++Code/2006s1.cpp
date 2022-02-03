#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


string solve(string a, string b, string baby) {
	for (int i=0; i<a.length(); i+=2) {
		int dom = 0;
		
		int cap1=0, cap2=0;
		if (a[i]<'a') cap1++;
		if (a[i+1]<'a') cap1++;
		if (b[i]<'a') cap2++;
		if (b[i+1]<'a') cap2++;
		if (cap1==2 || cap2==2) dom=1;
		else if (cap1==1 || cap2==1) dom=2;
		
		if (dom==0) {
			if (baby[i/2]>='a') continue;
			return "Not their baby!";
		}
		else if (dom==1) {
			if (baby[i/2]<'a') continue;
			return "Not their baby!";
		}
	}
	return "Possible baby.";
}

int main() {
	string p1; cin>>p1;
	string p2; cin>>p2;
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		string baby; cin>>baby;
		cout<< solve(p1,p2,baby) <<endl;
	}
}