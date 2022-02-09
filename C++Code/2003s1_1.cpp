#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	unordered_map<int,int> t;
	t[54]=19;
	t[90]=48;
	t[99]=77;
	t[9]=34;
	t[40]=64;
	t[67]=86;

	int pos=1;
	int n=1;
	while (n) {
		cin>>n;
		if (n==0) {
			cout << "You Quit!" << endl;
			break;
		}
		int newPos=pos+n;
		if (t[newPos]) newPos=t[newPos];
		if (newPos<=100) {
			pos=newPos;
			if (pos==100) {
				cout << "You are now on square " << pos << endl;
				cout << "You Win!" << endl;
				break;
			}
		}
		cout << "You are now on square " << pos << endl;

	}
}