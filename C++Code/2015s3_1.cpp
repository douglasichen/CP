#include <bits/stdc++.h>
using namespace std;

struct Next {
	int *loc = new int(-1);
};

int g, a[100001];
Next nexts[100001];

int main() {
	cin>>g;
	for (int i=1; i<=g; i++) {
		cin>>a[i];
		Next next = nexts[a[i]];
		*next.loc=a[i];
	}
	for (int i=1; i<=g; i++) {
		int plane = a[i];
		Next next = nexts[plane];
		cout << next.loc << ": " << *next.loc << endl;
	}
	for (int i=1; i<=g; i++) {
		int plane = a[i];
		Next next = nexts[plane];
		(*next.loc)--;
		cout << next.loc << ": " << *next.loc << endl;
		// Next belowNext = nexts[*next.loc];
		// belowNext.loc=next.loc;

		// cout << "next: " << *belowNext.loc << endl;
		
	}
}