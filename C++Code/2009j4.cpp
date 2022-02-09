#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	vector<string> v = {
		"WELCOME",
		"TO",
		"CCC",
		"GOOD",
		"LUCK",
		"TODAY"
	};
	vector<string> l1,l2;
	l1.push_back(v[0]);
	
	int n; cin>>n;
	int fSize=v[0].size();
	int space1=n-fSize;
	bool l2Start=1;
	for (int i=1; i<v.size(); i++) {
		int nextSpace1=space1-v[i].size()-1;
		// cout << "nextSpace: " << nextSpace1 << endl;
		if (nextSpace1>=0) {
			l1.push_back(v[i]);
			space1=nextSpace1;
		}
		else {
			l2Start=i;
			break;
		}
	}
	
	for (int i=l2Start; i<v.size(); i++) {
		l2.push_back(v[i]);
	}
	

	for (string s : l1) cout << s << ' ';
	cout << endl;
	for (string s : l2) cout << s << ' ';
	cout << endl;

	string firstL="", secondL="";
	firstL += l1[0];

	int l2s=0;
	if (l2.size()-1>0) {
		l2s=l2.size()-1;
		secondL += l2[0];
	}

	int l1s=l1.size()-1;
	// cout << l1s << ' ' << l2s << endl;

	int left1=0;
	for (string s : l1) left1+=s.size();
	left1 = n-left1;

	int left2=0;
	for (string s : l2) left2+=s.size();
	left2 = n-left2;	
	// cout << "here1" << endl;
	if (l1s) {
		int	w1=left1/l1s;
		int ex1=left1-w1*l1s;
		string spaces1(w1,'.');
		for (int i=1; i<l1.size(); i++) {
			if (ex1) {
				firstL+='.';
				ex1--;
			}
			firstL += spaces1;
			firstL += l1[i];
		}
	}
	if (l2s) {
		cout << "l2s: " << l2s << endl;
		cout << "here2" << endl;
		int w2=left2/l2s;
		int ex2=left2-w2*l2s;
		string spaces2(w2,'.');

		// cout << "l2 size: " << l2.size() << endl;
		for (int i=1; i<l2.size(); i++) {
			if (ex2) {
				secondL+='.';
				ex2--;
			}
			secondL += spaces2;
			secondL += l2[i];
		}
	}
	else {
		string newSpace(n-l2[0].size(),'.');
		secondL += newSpace;
	}

	cout << firstL << endl;
	cout << secondL << endl;

}